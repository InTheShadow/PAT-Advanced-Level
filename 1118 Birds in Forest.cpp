#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 10010;

int father[MAXN];
int isRoot[MAXN] = {0};
bool vis[MAXN] = {false};

void init(){
	for(int i = 0;i < MAXN;i++){
		father[i] = i;
	}
}

int findFather(int x){
	int a = x;
	while(father[x] != x) x = father[x];
	
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb){
		father[fb] = fa;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	init();
	for(int i = 0;i < n;i++){
		int k,first;
		scanf("%d",&k);
		if(k != 0) {
			scanf("%d",&first);
			vis[first] = true;
		}
		for(int j = 1;j < k;j++){
			int x;
			scanf("%d",&x);
			vis[x] = true;
			Union(first,x);
		}
	}
	
	int birds = 0,trees = 0;
	for(int i = 0;i < MAXN;i++){
		if(vis[i] == true){
			isRoot[findFather(i)]++;	
		}
	}
	
	for(int i = 0; i < MAXN;i++){
		if(isRoot[i] > 0) trees++;
		birds += isRoot[i];
	}
	
	int k;
	printf("%d %d\n",trees,birds);
	scanf("%d",&k);
	for(int i = 0; i < k;i++){
		int id1,id2;
		scanf("%d %d",&id1,&id2);
		if(findFather(id1) == findFather(id2)) printf("Yes\n");
		else printf("No\n");
	}
}
