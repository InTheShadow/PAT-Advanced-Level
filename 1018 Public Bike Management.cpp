#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 99999999;
int road[505][505],dist[505],weight[505];
bool visit[505];
vector<int> pre[505];
vector<int> path,tempPath;
int minNeed = inf,minSend = inf;

void dfs(int v){
	if(v == 0){
		int need = 0,send = 0;
		tempPath.push_back(v);
		for(int i = tempPath.size()-1;i>=0;i--){
			int id = tempPath[i];
			if(weight[id] > 0) send += weight[id];
			else  if(send >= (0 - weight[id])) {
				send += weight[id];
			}
			else {
				need += (0-weight[id]-send);
				send = 0;
			}
		}
		if(need < minNeed) {
			minNeed = need;
			minSend = send;
			path = tempPath;
		}
		else if(need == minNeed && send < minSend){
			minSend = send;
			path = tempPath;
		}
		tempPath.pop_back();
	}
	else{
		tempPath.push_back(v);
		for(int i = 0;i < pre[v].size();i++) dfs(pre[v][i]);
		tempPath.pop_back();
	}
}

int main(){
	//scanf
	int c,n,sp,m;
	fill(road[0],road[0]+505*505,inf);
	fill(dist,dist+505,inf);
	fill(visit,visit+505,false);
	scanf("%d%d%d%d",&c,&n,&sp,&m);
	for(int i = 1;i <= n;i++) {
		scanf("%d",&weight[i]);
		weight[i] = weight[i] - c/2;
	}
	for(int i = 1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		scanf("%d",&road[u][v]);
		road[v][u] = road[u][v];
	}
	//dijstra
	dist[0] = 0;
	for(int i = 0;i <= n;i++){
		int u = -1,minn = inf;
		for(int j = 0;j<=n;j++){
			if(visit[j] == false && dist[j] < minn) {
				minn = dist[j];
				u = j;
			}
		}
		if(u == -1) break;
		visit[u] = true;
		dist[u] = minn;
		for(int v = 0; v<= n;v++){
			if(visit[v] == false && road[u][v] != inf){
				if(road[u][v] + dist[u] < dist[v] ){
					dist[v] = dist[u] + road[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(road[u][v] + dist[u] == dist[v]){
					pre[v].push_back(u);
				}
			}
		}	
	}
	//dfs
	dfs(sp); 
	printf("%d 0",minNeed);
	for(int i = path.size()-2; i >= 0;i--){
		printf("->%d",path[i]);
	}
	printf(" %d",minSend);
	
} 


