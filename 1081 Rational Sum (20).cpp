#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;

int gcd(int a, int b){
	return (b == 0) ? a : gcd(b,a%b);
}

struct Fraction{
	LL up,down;
};

Fraction simplify(Fraction a){
	if(a.down < 0) {
		a.up = - a.up;
		a.down = - a.down;
	}
	
	if(a.up == 0) a.down = 1;
	else {
		int d = gcd(a.up,a.down);
		a.up /= d;
		a.down /= d;
	}
	return a;
}

Fraction add(Fraction a,Fraction b){
	Fraction res;
	res.up = a.up*b.down + a.down*b.up;
	res.down = a.down*b.down;
	return simplify(res);
}

void showResult(Fraction a){
	simplify(a);
	if(a.down == 1) printf("%lld\n",a.up);
	else if(abs(a.up) > a.down){
		printf("%lld %lld/%lld\n",a.up/a.down,abs(a.up)%a.down,a.down);
	} 
	else printf("%lld/%lld\n",a.up,a.down);
}

int main(){
	int n;
	Fraction sum,temp;
	sum.up = 0;
	sum.down = 1;
	scanf("%d",&n);
	for(int i = 0; i < n;i++){
		scanf("%lld/%lld",&temp.up,&temp.down);
		sum = add(sum,temp);
	}
	showResult(sum);
}
