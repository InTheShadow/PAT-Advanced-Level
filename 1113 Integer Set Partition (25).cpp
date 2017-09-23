#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100010;

int a[MAXN];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int k = n/2;
	int n12 = n-2*k;
	int s1 = 0,s2 = 0;
	for(int i = 1; i <=k;i++){
		s1 += a[i];
	}
	
	for(int i = k+1;i <= n;i++){
		s2 += a[i];
	}
	printf("%d %d\n",n12,s2-s1);
}
