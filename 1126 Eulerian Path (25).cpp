#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXV = 510;

vector<int> adj[MAXV];
bool vis[MAXV] = {false};

int n;

int dfs(int root){
	vis[root] = true;
	int cnt = 1;
	for(int i = 0;i < adj[root].size();i++){
		int temp = adj[root][i];
		if(vis[temp] == false){
			cnt += dfs(temp);
		}
	}
	
	return cnt;
}

int main(){
	int m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int even = 0;
	for(int i = 1; i <= n;i++){
		printf("%d",adj[i].size());
		if(i != n) printf(" ");
		if(adj[i].size() % 2 == 0) even++; 
	}
	
	printf("\n");
	int cnt = dfs(1);
	if(cnt == n && even == n) {
		printf("Eulerian\n");
	}
	else if(cnt ==n && even == n-2){
		printf("Semi-Eulerian\n");
	}
	else printf("Non-Eulerian\n");
}


