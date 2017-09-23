#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 100010;
int a[maxn];
vector<int> overD;

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	
	sort(a,a+n);
	
	overD.resize(a[n-1]+1);
	int max = a[n-1],j = n-2;
	overD[max] = 0;
	for(int i = max - 1;i>=0;i--){
		while(i < a[j]) j--;
		overD[i] = n-1-j;
	}
	
	int i = 0;
	for( i = 0; i < max;i++){
		if(overD[i+1] < i+1) break;
	}
	
	
	printf("%d\n",i);
	
}
