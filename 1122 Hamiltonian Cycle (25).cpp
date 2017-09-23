#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXV = 210;
bool G[MAXV][MAXV] = {false};
int times[MAXV] = {0};

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i = 0;i < M;i++){
		int id1,id2;
		scanf("%d %d",&id1,&id2);
		G[id1][id2] = true;
		G[id2][id1] = true;
	}
	
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		fill(times+1,times+N+1,0);
		int k ,first,last;
		bool flag = true;
		scanf("%d",&k);
		scanf("%d",&first);
		times[first]++;
		last = first;
		if(k != N+1) flag = false;
		for(int i = 1;i < k;i++){
			int x;
			scanf("%d",&x);
			if(G[last][x] == false) {
				flag = false;
			}
			times[x]++;
			last = x;
		}
		if(last != first) flag = false;
		for(int i = 1;i <= N;i++){
			if(first == i && times[i] != 2) flag = false;
			else if(first != i && times[i] != 1) flag = false;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
}
