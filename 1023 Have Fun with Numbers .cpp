#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
char num[22];
char book[10];

int main(){
	scanf("%s",num);
	int len = strlen(num);
	int flag = 0;
	fill(book,book+10,0);
	for(int i = len -1;i>=0;i--){
		int temp = num[i] - '0';
		book[temp]++;
		temp = temp*2+flag;
		flag = 0;
		if(temp >= 10){
			flag = 1;
			temp = temp-10;
		}
		book[temp]--;
		num[i] = (temp+'0');
	}
	int flag2 = 0;
	for(int i = 0; i < 10;i++){
		if(book[i] != 0) {
			flag2 = 1;
			break;	
		}
	}
	if(flag == 1 || flag2 == 1) printf("No\n");
	else printf("Yes\n");
	if(flag == 1) printf("1");
	printf("%s",num);
}
