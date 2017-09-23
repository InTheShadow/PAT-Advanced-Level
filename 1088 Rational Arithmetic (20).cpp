#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b){
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
		LL d = gcd(abs(a.down),abs(a.up));
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

Fraction sub(Fraction a,Fraction b){
	Fraction res;
	res.up = a.up*b.down - a.down*b.up;
	res.down = a.down*b.down;
	return simplify(res);
}

Fraction divide(Fraction a,Fraction b){
	Fraction res;
	res.up = a.up*b.down;
	res.down = a.down*b.up;
	return simplify(res);
}

Fraction multi(Fraction a,Fraction b){
	Fraction res;
	res.up = a.up*b.up;
	res.down = a.down*b.down;
	return simplify(res);
}

void showResult(Fraction a){
	a = simplify(a);
	if(a.up < 0) printf("(");
	if(a.down == 1) printf("%lld",a.up);
	else if(abs(a.up) > a.down){
		printf("%lld %lld/%lld",a.up/a.down,abs(a.up)%a.down,a.down);
	} 
	else printf("%lld/%lld",a.up,a.down);
	if(a.up < 0) printf(")");
}

int main(){
	Fraction a,b;
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
	
	showResult(a);
	printf(" + ");
	showResult(b);
	printf(" = ");
	showResult(add(a,b));
	printf("\n");
	
	showResult(a);
	printf(" - ");
	showResult(b);
	printf(" = ");
	showResult(sub(a,b));
	printf("\n");
	
	showResult(a);
	printf(" * ");
	showResult(b);
	printf(" = ");
	showResult(multi(a,b));
	printf("\n");
	
	showResult(a);
	printf(" / ");
	showResult(b);
	printf(" = ");
	if(b.up == 0) printf("Inf");
	else showResult(divide(a,b));
	printf("\n");
	
}
