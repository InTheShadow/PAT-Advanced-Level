#include<cstdio>
#include<algorithm>
using namespace std;
int e[505][505],dist[505],weight[505],num[505],w[505];
bool visit[505];
const int inf = 99999999;

int main(){
	int n,m,c1,c2;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	fill(e[0],e[0]+505*505,inf);
	fill(dist,dist+505,inf);
	fill(visit,visit+505,false);
	for(int i = 0;i < n;i++){
		scanf("%d",&weight[i]);
	}
	
	for(int i = 0;i<m;i++){
		int from,to;
		scanf("%d%d",&from,&to);
		scanf("%d",&e[from][to]);
		e[to][from] = e[from][to];
	}
	
	//dijstra
	dist[c1] = 0;
	w[c1] = weight[c1];
	num[c1] = 1;
	for(int i = 0; i< n;i++){
		int u = -1,minn = inf;
		for(int j = 0; j < n;j++){
			if(visit[j] == false && dist[j] < minn){
				minn = dist[j];
				u = j;
			}
		}
		if(u == -1) break;
		visit[u] = true;
		for(int v = 0; v< n;v++){
			if(visit[v] == false && e[u][v] != inf){
				if(dist[u] + e[u][v] < dist[v]) {
					dist[v] = dist[u] + e[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				}
				else if(dist[u] + e[u][v] == dist[v]){
					num[v] = num[u] + num[v];
					if(w[u] + weight[v] > w[v]) w[v] = w[u] + weight[v];
 				}
			}
		}
	}
	
	printf("%d %d",num[c2],w[c2]);
}
