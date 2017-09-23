#include<cstdio>
#include<algorithm>
using namespace std;

int book[201] = {0},dp[10001],sp[10001];

int main(){
	int n,m,l,num=1;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i = 1;i<=m;i++){
		int x;
		scanf("%d",&x);
		book[x] = i;
	}
	scanf("%d",&l);
	for(int i = 1;i<=l;i++){
		int x;
		scanf("%d",&x);
		if(book[x] >= 1) sp[num++] = book[x];
	}
	num--;
	int maxn = 0;
	for(int i = 1;i<=num;i++){
		dp[i] = 1;
		for(int j = 1;j < i;j++){
			if(sp[i] >= sp[j]) dp[i] = max(dp[i],dp[j]+1);
		}	
		maxn = max(maxn,dp[i]);
	}
	printf("%d",maxn);
}
