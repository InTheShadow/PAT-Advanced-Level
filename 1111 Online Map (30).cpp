#include<cstdio>
#include<vector>
#include<cstring> 
#include<algorithm>
using namespace std;

const int INF = 0x3fffffff;
const int MAXN = 520;

int n,sta,des;
int GD[MAXN][MAXN];
int GT[MAXN][MAXN];


int dd[MAXN];
int dt[MAXN];
int pt[MAXN];
bool vis[MAXN];
int pre[MAXN];

vector<int> dPath,tPath;

void dijkGD(int s){
	fill(dd,dd+n,INF);
	fill(dt,dt+n,INF);
	memset(vis,false,sizeof(vis[0])*n);
	for(int i = 0; i < n;i++) pre[i] = i;
	dd[s] = 0;
	dt[s] = 0;
	for(int i = 0;i < n;i++){
		int u = -1,min = INF;
		for(int j = 0; j < n;j++){
			if(vis[j] == false && dd[j] < min){
				min = dd[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n;v++){
			if(vis[v] == false && GD[u][v] != INF){
				if(GD[u][v] + dd[u] < dd[v]){
					dd[v] = GD[u][v] + dd[u];
					dt[v] = GT[u][v] + dt[u]; 
					pre[v] = u;
				}
				else if(dd[v] == GD[u][v] + dd[u] 
					&& dt[u] + GT[u][v] < dt[v]){
						dt[v] = dt[u] + GT[u][v];
						pre[v] = u;
					}
			}
		}
	}
}

void printRoute(vector<int>& st){
	for(int i = 0; i < st.size();i++){
		printf("%d",st[i]);
		if(i != st.size() -1) printf(" -> ");
	}
	printf("\n");
}

void dijkGT(int s){
	fill(dt,dt+n,INF);
	fill(pt,pt+n,0);
	memset(vis,false,sizeof(vis[0])*n);
	for(int i = 0; i < n;i++) pre[i] = i;
	dt[s] = 0;
	pt[s] = 1;
	for(int i = 0;i < n;i++){
		int u = -1,min = INF;
		for(int j = 0; j < n;j++){
			if(vis[j] == false && dt[j] < min){
				min = dt[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n;v++){
			if(vis[v] == false && GT[u][v] != INF){
				if(GT[u][v] + dt[u] < dt[v]){
					dt[v] = GT[u][v] + dt[u];
					pt[v] = pt[u] + 1; 
					pre[v] = u;
				}
				else if(dt[v] == GT[u][v] + dt[u] 
					&& pt[u] + 1 < pt[v]){
						pt[v] = pt[u] + 1;
						pre[v] = u;
					}
			}
		}
	}
}

void getDPath(int v){
	if(v == sta) {
		dPath.push_back(v);
		return;
	}
	getDPath(pre[v]);
	dPath.push_back(v);
}

void getTPath(int v){
	if(v == sta) {
		tPath.push_back(v);
		return;
	}
	getTPath(pre[v]);
	tPath.push_back(v);
}

bool isIdentical(){
	if(dPath.size() != tPath.size()) return false;
	for(int i = 0; i < dPath.size();i++){
		if(dPath[i] != tPath[i]) return false;
	}
	return true;
}

int main(){
	int m;
	scanf("%d%d",&n,&m);
	fill(GD[0],GD[0]+MAXN*MAXN,INF);
	fill(GT[0],GT[0]+MAXN*MAXN,INF);
	for(int i = 0; i < m;i++){
		int id1,id2,ow,l,t;
		scanf("%d%d%d%d%d",&id1,&id2,&ow,&l,&t);
		if(ow == 1){
			GD[id1][id2] = l;
			GT[id1][id2] = t;
		}
		else {
			GD[id1][id2] = l;
			GD[id2][id1] = l;
			GT[id1][id2] = t;
			GT[id2][id1] = t;
		}
	}
	
	scanf("%d%d",&sta,&des);
	dijkGD(sta);
	getDPath(des);
	dijkGT(sta);
	getTPath(des);
	if(isIdentical()){
		printf("Distance = %d; Time = %d: ",dd[des],dt[des]);
		printRoute(dPath);
	}
	else {
		printf("Distance = %d: ",dd[des]);
		printRoute(dPath);
		printf("Time = %d: ",dt[des]);
		printRoute(tPath);
	}
}
