#include<cstdio>
using namespace std;
int main(){
	double A[1001] = {0.0},res[2001] = {0.0};
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		int exp;
		scanf("%d",&exp);
		scanf("%lf",&A[exp]);
	} 
	
	scanf("%d",&n);
	for(int i = 0; i<n;i++){
		int exp;
		double coef;
		scanf("%d",&exp);
		scanf("%lf",&coef);
		for(int j = 0;j<1001;j++){
			res[exp+j] += A[j]*coef;
		}
	}
	
	int count = 0;
	for(int i = 0;i<2001;i++){
		if(res[i] != 0.0) count++;
	}
	
	printf("%d",count);
	for(int i = 2000;i>=0;i--){
		if(res[i] != 0.0) printf(" %d %.1lf",i,res[i]);
	}

}
