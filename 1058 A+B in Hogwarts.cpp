#include<cstdio>

int main(){
	int a[3],b[3],c[3];
	scanf("%d.%d.%d %d.%d.%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
	int carry = 0;
	int P[3] = {1,17,29};
	for(int i = 2 ; i >= 0;i--){
		if(i != 0) c[i] = (a[i] + b[i] +  carry) % P[i];
		else c[i] = a[i] + b[i] + carry;
		carry = (a[i] + b[i] + carry) / P[i];
	}
	printf("%d.%d.%d\n",c[0],c[1],c[2]);
}
