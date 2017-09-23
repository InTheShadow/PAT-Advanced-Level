#include<cstdio>
#include<cmath>
using namespace std;
int left[11],right[11],now[11];

int main(){
	//scanf
	int n;
	scanf("%d",&n);
	int m = 1;
	while(n != 0){
		now[m] = n%10;
		left[m] = n = n/10;
		if(m == 1) right[m] = 0;
		else right[m] = now[m-1]*int(pow(10,m-2)) + right[m-1];
		m++;
	}
	m--;
	int sum = 0;
	for(int i = 1; i <= m;i++){
		if(now[i] > 1) sum += int(pow(10,i-1));
		else if(now[i] == 1) sum += right[i] + 1;
		
		sum += left[i]*int(pow(10,i-1)); 
	}
	
	printf("%d",sum);
}
