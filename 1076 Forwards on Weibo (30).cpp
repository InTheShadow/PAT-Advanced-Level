#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int MAXN = 1010;
int n,l;

struct Node{
	int layer;
	vector<int> adj;
} nodes[MAXN];

bool inq[MAXN];

int bfs(int root){
	fill(inq+1,inq+1+n,false);
	queue<int> q;
	q.push(root);
	inq[root] = true;
	int res = 0;
	nodes[root].layer = 0;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		int layer = nodes[temp].layer;
		for(int i = 0;i < nodes[temp].adj.size();i++ ){
			int next = nodes[temp].adj[i];
			if(inq[next] == false && layer+1 <= l){
				nodes[next].layer = layer+1;
				q.push(next);
				res++;
				inq[next] = true;
			}
		}
	}
	return res;
}

int main(){
	scanf("%d %d",&n,&l);
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%d",&k);
		for(int j = 0;j < k;j++){
			int id;
			scanf("%d",&id);
			nodes[id].adj.push_back(i);
		}
	}
	
	int k;
	scanf("%d",&k);
	for(int i = 0;i < k;i++){
		int x;
		scanf("%d",&x);
		printf("%d\n",bfs(x));
	}
}
