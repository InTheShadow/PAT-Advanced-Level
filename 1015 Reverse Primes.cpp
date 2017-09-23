#include<cstdio>
#include<cmath>
using namespace std;

bool isPrime(int n){
	if(n <= 1) return false;
	int sqr = int(sqrt(n*1.0));
	for(int i = 2;i<=sqrt(n*1.0);i++){
		if(n%i == 0) return false;
	}
	return true;
}

int getReverseNum(int n,int d){
	int result = 0;
	while(n/d != 0){
		result = result*d+n%d;
		n = n/d;
	}
	result = result*d+n%d;
	return result;
}

int main(){
	int n,d;
	while(scanf("%d",&n) != EOF){
		if(n<0) break;
		scanf("%d",&d);
		if(isPrime(n) && isPrime(getReverseNum(n,d))) printf("Yes\n"); 
		else printf("No\n");
	}
}
