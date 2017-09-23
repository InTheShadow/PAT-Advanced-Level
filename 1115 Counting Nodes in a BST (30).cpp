#include<cstdio>
#include<queue>
using namespace std;

const  int MAXN = 1010;

struct Node{
	int data;
	int left;
	int right;
	int layer;
}nodes[MAXN];

int getMaxLayer(int root){
	queue<int> q;
	nodes[root].layer = 1;
	q.push(root);
	int maxLayer = 1;
	while(!q.empty()){
		int top = q.front(),temp;
		q.pop();
		maxLayer = nodes[top].layer;
		if(nodes[top].left != -1) {
			temp = nodes[top].left;
			nodes[temp].layer = maxLayer+1;
			q.push(temp);
		}
		if(nodes[top].right != -1) {
			temp = nodes[top].right;
			nodes[temp].layer = maxLayer+1;
			q.push(temp);
		}
	}
	return maxLayer; 
}
int index = 0;
int newNode(int x){
	nodes[index].left = -1;
	nodes[index].right = -1;
	nodes[index].data = x;
	return index++;
}

void insert(int& root ,int x){
	if(root == -1){
		root = newNode(x);
		return;
	}
	if(nodes[root].data > x)insert(nodes[root].left,x);
	else insert(nodes[root].right,x);
}

int main(){
	int n;
	for(int i = 0; i < MAXN;i++){
		nodes[i].layer = -1;
	}
	scanf("%d",&n);
	int root = -1;
	for(int i = 0 ;i < n;i++){
		int x;
		scanf("%d",&x);
		insert(root,x);
	} 
	int maxLayer = getMaxLayer(root);
	int n1 = 0,n2 = 0;
	for(int i = 0;i < MAXN;i++)
	{
		if(nodes[i].layer == maxLayer) n1++;
		else if(nodes[i].layer == maxLayer-1) n2++; 
	}
	printf("%d + %d = %d",n1,n2,n1+n2);
	return 0;
}
