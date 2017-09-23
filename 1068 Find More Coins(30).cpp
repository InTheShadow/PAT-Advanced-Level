#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 10010;
const int MAXM = 110;

int dp[MAXM] = {0};
bool choice[MAXN][MAXM] = {false}; 
bool flag[MAXN];
int w[MAXN];
int n,m;
void getDP(){
	for(int i = 1; i <= n;i++){
		for(int v = m; v >= w[i]; v--){
			if(dp[v] <= dp[v-w[i]]+w[i]) {
				dp[v] = dp[v-w[i]]+w[i];
				choice[i][v] = true;
			}
			else {
				choice[i][v] = false;
			}
		}
	}
}

void printRes(){
	int i = n,v = m,num = 0;
	if(dp[m] != m) printf("No Solution\n");
	else {
		while(i > 0){
			if(choice[i][v]){
				flag[i] = true;
				v -= w[i];
				num++;
			}
			else {
				flag[i] = false;
			}
			i--;
		}
	}
	
	for(int i = n;i >= 1;i--){
		if(flag[i]) {
			printf("%d",w[i]);
			num--;
			if(num > 0) printf(" ");
		}
	}
}

int cmp(int a,int b){
	return a > b;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1; i<=n;i++){
		scanf("%d",&w[i]);
	}
	sort(w+1,w+n+1,cmp);
	getDP();
	printRes();
}
 
