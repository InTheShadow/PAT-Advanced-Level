#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N,K,P;
vector<int> temp,ans,fac;

int pow(int x){
	int sum = 1;
	for(int i = 1; i <= P;i++){
		sum = sum*x;
	}
	return sum;
}

void getFac(){
	int res = 0,x = 1;;
	while(res <= N){
		fac.push_back(res);
		res = pow(x);
		x++;
	}	
}

int maxSum = -1; 
void dfs(int index,int n,int sum,int sumP){
	if(n == K && sumP == N && sum > maxSum){
		maxSum = sum;
		ans = temp;
		return;
	}
	if(sumP > N || n > K) return;
	if(index < 1) return;
	temp.push_back(index);
	dfs(index,n+1,sum+index,sumP+fac[index]);
	temp.pop_back();
	dfs(index-1,n,sum,sumP);
}

int main(){
	scanf("%d%d%d",&N,&K,&P);
	getFac();
	dfs(fac.size()-1,0,0,0);
	if(ans.size() == 0) {
		printf("Impossible\n");
	}
	else {
		printf("%d =",N);
		for(int i = 0; i < ans.size();i++){
			printf(" %d^%d",ans[i],P);
			if(i != ans.size()-1) printf(" +");
		}
		printf("\n");
	}
}
