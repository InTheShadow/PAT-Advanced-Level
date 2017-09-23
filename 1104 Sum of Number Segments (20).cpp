#include<cstdio>
using namespace std;

int main(){
	int n;
	double v,sum = 0.0;
	scanf("%d",&n);
	for(int i = 1; i <= n;i++){
		scanf("%lf",&v);
		sum += v*i*(n+1-i);
	}
	printf("%.2f\n",sum);
	
}
