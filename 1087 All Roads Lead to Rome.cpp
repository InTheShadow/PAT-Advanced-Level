#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
using namespace std;

const int INF = 0x3fffffff;
const int MAXV = 210;
int n,G[MAXV][MAXV],d[MAXV];
int weight[MAXV],w[MAXV] = {0};
int num[MAXV] = {0};
int pt[MAXV] = {0};
bool vis[MAXV] = {false};
int pre[MAXV];
map<int,string> i2s;
map<string,int> s2i;


void Dijkstra(int s){
	fill(d,d+MAXV,INF);
	for(int i = 0;i < n;i++) pre[i] = i;
	d[s] = 0;
	num[s] = 1;
	w[s] = weight[s];
	for(int i = 0; i < n;i++){
		int u = -1,min = INF;
		for(int j = 0;j < n;j++){
			if(vis[j] == false && d[j] < min){
				min = d[j];
				u = j;
			}  
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n;v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u]+ G[u][v];
					pt[v] = pt[u] + 1;
					w[v] = w[u] + weight[v];
					num[v] = num[u];
					pre[v] = u; 
				}
				else if(d[u] + G[u][v] == d[v]){
					num[v] += num[u];
					if(w[u] + weight[v] > w[v]){
						w[v] = weight[v] + w[u];
						pre[v] = u;
						pt[v] = pt[u] + 1;
					}
					else if(w[u] + weight[v] == w[v] && pt[u] + 1 < pt[v]){
						pt[v] = pt[u]+1;
						pre[v] = u; 
					}
				}
			}
		}
	}	
}

void printRoute(int v){
	if(v == 0) {
		cout << i2s[v];
		return;
	}
	printRoute(pre[v]);
	cout << "->" << i2s[v];
}

int main(){
	string temp;
	int k;
	cin >> n >> k >> temp;
	s2i[temp] = 0;
	i2s[0] = temp;
	weight[0] = 0;
	fill(G[0],G[0]+MAXV*MAXV,INF);
	for(int i = 1;i < n;i++){
		cin >> temp >> weight[i];
		s2i[temp] = i;
		i2s[i] = temp;
	}
	for(int i = 0; i < k;i++){
		string temp2;
		cin >> temp >> temp2;
		int t;
		cin >> t;
		G[s2i[temp]][s2i[temp2]] = t;
		G[s2i[temp2]][s2i[temp]] = t;
	}
	Dijkstra(0);
	int f = s2i["ROM"];
	cout << num[f] << " " << d[f] << " " << w[f] << " " << w[f]/pt[f] << endl;
	printRoute(f);
	cout << endl;
}
