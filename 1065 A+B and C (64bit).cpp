#include<cstdio>

typedef long long LL;

int main(){
	LL a,b,c;
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		LL sum = a + b;
		bool flag;
		if(a > 0 && b > 0 && sum < 0) flag = true;
		else if( a < 0 && b < 0 && sum >= 0 ) flag = false;
		else flag = (sum > c);
		if(flag) printf("Case #%d: true\n",i);
		else printf("Case #%d: false\n",i);
	}
}
