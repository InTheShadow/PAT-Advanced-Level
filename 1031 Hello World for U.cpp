#include<cstdio>
#include<cstring>
using namespace std;
char str[85];

int main(){
	scanf("%s",str);
	int n = strlen(str);
	int n1,n2,n3;
	switch((n+2)%3){
		case 0:n1 = n2 = n3 = (n+2)/3;break;
		case 1:n1 = n3 = (n+2)/3;n2 = n1 + 1;break;
		case 2:n1 = n3 = (n+2)/3;n2 = n1 + 2;break;
		default: break;
	}
	for(int i = 0; i < n1 - 1;i++){
		printf("%c",str[i]);
		for(int j = 0;j < n2-2;j++){
			printf(" ");
		}
		printf("%c\n",str[n-1-i]);
	}
	
	for(int i = n1 - 1;i < n1 + n2 - 1;i++){
		printf("%c",str[i]);
	}
	printf("\n");
}
