#include<cstdio>
#include<vector>
#define INF 999999999
using namespace std;


vector<int> sum;
vector<int> ans;
int mm = INF,n,m;
void search(int i){
	int left = i,right = n;
	while(left <  right){
		int mid = (left+right)/2;
		if(sum[mid] - sum[i-1] >= m){
			right = mid ;
		}
		else left = mid + 1;
	}
	if(sum[right] - sum[i-1] >= m){
		ans[i] = right;
		if(sum[right] - sum[i-1] < mm ) mm = sum[right] - sum[i-1];
	}
	else ans[i] = -1;

	
}

int main(){
	scanf("%d%d",&n,&m);
	sum.resize(n+1);
	ans.resize(n+1);
	sum[0] = 0;
	for(int i = 1;i <= n;i++){
		int num;
		scanf("%d",&num);
		sum[i] = sum[i-1]+num;
	}
	for(int i = 1;i <= n;i++){
		search(i);
	}
	
	for(int i = 1;i <= n;i++){
		if(ans[i] != -1){
			if(sum[ans[i]] - sum[i-1] == mm) printf("%d-%d\n",i,ans[i]); 
		}
	}
	
	
}
