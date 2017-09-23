#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 100010;

struct factor{
	int count;
	int value;
}fac[10];

int prime[maxn];
bool p[maxn] = {false};
int pNum = 0;
void getPrimes(int n){
	for(int i = 2;i <= n;i++){
		if(p[i] == false) {
			prime[pNum++] = i;
			for(int j = i*i;j <= n;j*=i){
				p[j] = true;
			}
		}	
	}
}

int num = 0;
void getFactors(int n){
	int sqr = (int)sqrt(n*1.0),temp = 1;
	getPrimes(sqr);
	for(int i = 0 ;i < pNum;i++){
		if(n % prime[i] == 0) {
			fac[num].count = 0;
			fac[num].value = prime[i];
			while(n % prime[i] == 0){
				fac[num].count++;
				n /= prime[i];
			}
			num++;
		}
	}
	
	if(n != 1) {
		fac[num].value = n;
		fac[num].count = 1;
		num++;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	if(n == 1) {
		printf("1=1");
		return 0;
	}
	getFactors(n);
	printf("%d=",n);
	for(int i = 0; i < num;i++){
		if(fac[i].count > 1)printf("%d^%d",fac[i].value,fac[i].count);
		else printf("%d",fac[i].value);
		if(i != num-1) printf("*");
	}
	return 0;
}
