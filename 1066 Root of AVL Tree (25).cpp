#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct Node{
	int v,height;
	Node *lchild,*rchild;
	int index;
}*root;

Node* newNode(int v){
	Node* temp = new Node;
	temp->v = v;
	temp->height = 1;
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;
} 

int getHeight(Node* root){
	if(root == NULL) return 0;
	else return root->height;
}

void updateHeight(Node* root){
	root->height = max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

int getBalanceFactor(Node* root){
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(Node* &root){
	Node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void R(Node* &root){
	Node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(Node* &root,int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	
	if(root->v > x){
		insert(root->lchild,x);
		updateHeight(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1){
				R(root);
			}
			else if(getBalanceFactor(root->lchild) == -1){
				L(root->lchild);
				R(root);
			}
		}
	}
	else {
		insert(root->rchild,x);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->rchild) == -1){
				L(root);
			} 
			else if(getBalanceFactor(root->rchild) == 1){
				R(root->rchild);
				L(root);
			}
		}
	} 
}

int n;
void levelOrder(Node* root){
	int index = 1;
	bool isComplete = true;
	root->index = index;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp->index != index && isComplete == true){
			isComplete = false;
		}
		printf("%d",temp->v);
		if(index != n) printf(" ");
		index++;
		if(temp->lchild != NULL){
			temp->lchild->index = 2*(temp->index);
			q.push(temp->lchild);
		}
		
		if(temp->rchild != NULL){
			temp->rchild->index = 2*(temp->index)+1;
			q.push(temp->rchild);
		}	
	}
	printf("\n");
	if(isComplete) printf("YES\n");
	else printf("NO\n"); 
}

int main(){

	scanf("%d",&n);
	root = NULL;
	for(int i = 0; i < n;i++){
		int x;
		scanf("%d",&x);
		insert(root,x);
	}
	levelOrder(root);
}
