#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int MAXN = 1010;
vector<int> G[MAXN];
bool vis[MAXN];
int n,m,k;
int deleteP; 
void dfs(int u){
	vis[u] = true;
	for(int i = 0;i < G[u].size();i++){
		if(vis[G[u][i]] == false){
			dfs(G[u][i]);
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0; i < m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for(int i = 0; i < k;i++){
		scanf("%d",&deleteP);
		memset(vis,false,sizeof(vis));
		vis[deleteP] = true;
		int ans = 0;
		for(int j = 1; j <= n;j++){
			if(vis[j] == false){
				dfs(j);
				ans++;
			} 
		}
		printf("%d\n",ans-1);
	}
	return 0;
}




