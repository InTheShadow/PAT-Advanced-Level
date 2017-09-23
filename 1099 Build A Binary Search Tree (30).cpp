#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXN = 110;

struct Node{
	int data;
	int left;
	int right;
}nodes[MAXN];

int in[MAXN];
int N;
int index = 0;
void inOrder(int root){
	if(root == -1) return;
	inOrder(nodes[root].left);
	nodes[root].data = in[index++];
	inOrder(nodes[root].right);
}

int levelI = 0;
void levelOrder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		printf("%d",nodes[top].data);
		if(levelI != N-1) printf(" ");
		levelI++;
		if(nodes[top].left != -1) q.push(nodes[top].left);
		if(nodes[top].right != -1) q.push(nodes[top].right);
	}
}

int main(){
	scanf("%d",&N);
	for(int i = 0; i < N;i++){
		scanf("%d%d",&nodes[i].left,&nodes[i].right);
	}
	for(int i = 0;i < N;i++){
		scanf("%d",&in[i]);
	}
	sort(in,in+N);
	inOrder(0);

	levelOrder(0);
	return 0;
}
