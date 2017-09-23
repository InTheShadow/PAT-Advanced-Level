#include<cstdio>
#include<algorithm>
using namespace std;

void to_array(int n,int num[]){
	for(int i = 0; i < 4;i++){
		num[i] = n % 10;
		n /= 10;
	}
}

int to_int(int num[]){
	int sum = 0, a = 1;
	for(int i = 0;i < 4;i++){
		sum += num[i]*a;
		a *= 10;
	}
	return sum;
}

bool cmp(int a,int b){
	return a > b;
}

int main(){
	int temp[4];
	int n,max,min;
	scanf("%d",&n);
	while(true){
		to_array(n,temp);
		sort(temp,temp+4);
		max = to_int(temp);
		sort(temp,temp+4,cmp);
		min = to_int(temp);	
		n = max - min;
		printf("%04d - %04d = %04d\n",max,min,n);
		if(n == 6174 || n == 0) break;
	}
}
