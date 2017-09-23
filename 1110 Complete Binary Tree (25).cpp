#include<cstdio>
#include<queue>
using namespace std;
const int MAXN = 25;

struct Node{
	int left;
	int right;
	int ind;
}nodes[MAXN];

bool vis[MAXN] = {false};
int n;
int ind = 1;
bool levelOrder(int root,int& last){
	queue<int> q;
	bool flag = true;
	nodes[root].ind = ind;
	q.push(root);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(nodes[top].ind != ind){
			flag = false;
		}
		if(ind == n) last = top;
		ind++;
		
		int temp;
		if(nodes[top].left != -1){
			temp = nodes[top].left;
			nodes[temp].ind = 2*nodes[top].ind;
			q.push(temp);
		}
		
		if(nodes[top].right != -1){
			temp = nodes[top].right;
			nodes[temp].ind = 2*nodes[top].ind + 1;
			q.push(temp);
		}
	}
	return flag;
}

int getID(char str[]){
	if(str[0] == '-') return -1;
	else {
		int x;
		sscanf(str,"%d",&x);
		return x;
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n;i++){
		char temp1[5],temp2[5];
		int left,right;
		scanf("%s %s",&temp1,&temp2);
		nodes[i].left = getID(temp1);
		if(nodes[i].left != -1) vis[nodes[i].left] = true;
		nodes[i].right = getID(temp2);
		if(nodes[i].right != -1) vis[nodes[i].right] = true;
	}
	int root = 0;
	while(vis[root] == true) root++;
	
	int last = -1;
	if(levelOrder(root,last)){
		printf("YES %d\n",last);
	}
	else {
		printf("NO %d\n",root);
	}
}
