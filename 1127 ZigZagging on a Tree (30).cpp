#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 35;

struct Node{
	int v;
	int left;
	int right;
	int layer;
}nodes[MAXN];

int index = 0;
int newNode(int x){
	nodes[index].v = x;
	nodes[index].left = -1;
	nodes[index].right = -1;
	return index++; 
}

int in[MAXN];
int post[MAXN];
int n;
void setTree(int& root,int inL,int inH,int postL,int postH){
	if(postL > postH) return;
	int data = post[postH];
	root = newNode(data);
	
	int k = 0;
	while(in[k] != data) k++;
	int numLeft = k - inL;
	setTree(nodes[root].left,inL,k-1,postL,postL+numLeft-1);
	setTree(nodes[root].right,k+1,inH,postL+numLeft,postH-1);
}

void zigzagOrder(int root){
	vector<int> v;
	v.push_back(root);
	nodes[root].layer = 1;
	int nowLayer = 1,nowI = 0;
	bool l2r = true;
	while(!v.empty()){
		int top = v[0];
		if(nodes[top].layer != nowLayer){
			nowLayer = nodes[top].layer;
			if(nowLayer != 2){
				reverse(v.begin(),v.end());
				l2r = !l2r;
			}
		}
		top = v[0];
		v.erase(v.begin());
		
		printf("%d",nodes[top].v);
		if(nowI != n-1) printf(" ");
		nowI++;
		
		int temp;
		if(l2r){
			if(nodes[top].left != -1){
				temp = nodes[top].left;
				v.push_back(temp);
				nodes[temp].layer = nowLayer+1;
			}
			if(nodes[top].right != -1){
				temp = nodes[top].right;
				v.push_back(temp);
				nodes[temp].layer = nowLayer+1;
			}
		}
		else {
			if(nodes[top].right != -1){
				temp = nodes[top].right;
				v.push_back(temp);
				nodes[temp].layer = nowLayer+1;
			}
			if(nodes[top].left != -1){
				temp = nodes[top].left;
				v.push_back(temp);
				nodes[temp].layer = nowLayer+1;
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&in[i]);
	}
	for(int i = 0;i < n;i++){
		scanf("%d",&post[i]);
	}
	int root = -1;
	setTree(root,0,n-1,0,n-1);
	zigzagOrder(root);
	printf("\n");
	return 0;
}


