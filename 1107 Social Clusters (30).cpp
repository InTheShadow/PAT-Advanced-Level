#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 1010;

int father[MAXN];
int course[MAXN] = {0};
int isRoot[MAXN] = {0};
int findFather(int x){
	int a = x;
	while(x != father[x]) x = father[x];
	while(a != father[a] ){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

int Union(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb){
		father[fa] = fb;
	}
}

void init(int n){
	for(int i = 1;i <= n;i++){
		father[i] = i;
	}
}

int cmp(int a,int b){
	return a > b;
}
int main(){
	int n;
	scanf("%d",&n);
	init(n);
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%d:",&k);
		for(int j = 0; j < k;j++){
			int c;
			scanf("%d",&c);
			if(course[c] == 0 ){
				course[c] = i;
			}
			Union(i,course[c]);
		}
	}
	
	for(int i = 1;i <=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans = 0;
	for(int i = 1;i <=n;i++){
		if(isRoot[i] != 0) ans++;
	}
	sort(isRoot+1,isRoot+n+1,cmp);
	printf("%d\n",ans);
	for(int i = 1;i <= ans;i++){
		printf("%d",isRoot[i]);
		if(i != ans) printf(" ");
	}
}
