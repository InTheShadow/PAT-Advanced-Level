#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXV = 1025;
const int INF = 0x3fffffff;

int n,m,G[MAXV][MAXV];
bool vis[MAXV];
int d[MAXV];

void Dijkstra(int s){
	memset(vis,false,sizeof(vis));
	fill(d,d+MAXV,INF);
	d[s] = 0;
	for(int i = 1; i <= n+m;i++){
		int u = -1,min = INF;
		for(int j = 1;j <= n+m;j++){
			if(vis[j] == false && d[j] < min){
				min = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		
		for(int v = 1; v <= n+m;v++){
			if(vis[v] == false && G[u][v] != INF 
			&& d[u] + G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
			}
		}
	}
}

int getID(char str[]){
	int temp;
	char c;
	if(str[0] == 'G'){
		sscanf(str,"%c%d",&c,&temp);
		temp += n;
	}
	else {
		sscanf(str,"%d",&temp);
	}
	return temp;
}

int main(){
	int ds,k;
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	fill(G[0],G[0] + MAXV*MAXV,INF);
	for(int i = 0; i < k;i++){
		char temp[20];
		scanf("%s",&temp);
		int id1 = getID(temp);
		scanf("%s",&temp);
		int id2 = getID(temp);
		int u;
		scanf("%d",&u);
		G[id1][id2] = u;
		G[id2][id1] = u;
	}
	
	double ansAvg = INF,ansDis = -1;
	int ansID = -1;
	for(int i = n+1;i <= n+m;i++){
		double avg = 0,minDis = INF;
		Dijkstra(i);
		for(int j = 1;j <= n;j++){
			if(d[j] > ds) {
				minDis = -1;
				break;
			}
			if(d[j] < minDis ) minDis = d[j];
			avg += 1.0*d[j]/n;
		}
		if(minDis == -1) continue;
		if(minDis > ansDis) {
			ansDis = minDis;
			ansAvg = avg;
			ansID = i;
		}
		else if(minDis == ansDis && avg < ansAvg){
			ansAvg = avg;
			ansID = i;
		}
	}
	
	if(ansID == -1) printf("No Solution");
	else {
		printf("G%d\n",ansID-n);
		printf("%.1f %.1f",ansDis,ansAvg);
	}
}
