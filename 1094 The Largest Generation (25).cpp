#include<cstdio>
#include<vector>
#include<queue> 
using namespace std;
const int maxn = 110;

struct Node{
	int level;
	vector<int> child;
}nodes[maxn];

int maxNum = 1;
int maxLevel = 1;
int n,m;

void levelOrder(int root){
	queue<int> q;
	nodes[root].level = 1;
	int nowLevel = 1;
	q.push(root);
	while(!q.empty()){
		int top = q.front();
		if(nowLevel != nodes[top].level){
			nowLevel = nodes[top].level;
			if(q.size() > maxNum){
				maxNum = q.size();
				maxLevel = nowLevel;
			}
		}
		q.pop();
		for(int i = 0; i < nodes[top].child.size();i++){
			int temp = nodes[top].child[i];
			nodes[temp].level = nodes[top].level+1;
			q.push(temp);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0;i < m;i++){
		int id,k;
		scanf("%d%d",&id,&k);
		nodes[id].child.resize(k);
		for(int j = 0; j < k;j++){
			scanf("%d",&nodes[id].child[j]);
		}
	}
	levelOrder(1);
	printf("%d %d\n",maxNum,maxLevel);
}

