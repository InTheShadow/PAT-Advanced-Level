#include<cstdio>
using namespace std;
int main(){
	char c[14] = "0123456789ABC";
	for(int i = 0; i<3;i++){
		int num;
		scanf("%d",&num);
		if(i == 0) printf("#");
		printf("%c%c",c[num/13],c[num%13]); 
	}
}
