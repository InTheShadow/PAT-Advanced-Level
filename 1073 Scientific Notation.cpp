#include<cstdio>
#include<cstring>
using namespace std;

char str[10001];
int main(){
	//scanf
	gets(str);
	
	//execute
	int pos = 1,len = strlen(str),exp = 0;
	if(str[0] == '-') printf("-");
	while(pos < len && str[pos] != 'E') pos++;
	for(int i = pos + 2;i < len;i++){
		exp = exp*10+str[i]-'0';
	}
	if(str[pos+1] == '-') exp = -exp;
	
	bool flag = false;
	if(exp < 0){
	 	for(int i = 1; i <= -exp;i++){
	 		printf("%c",'0');
	 		if(i==1 && flag == false) {
	 			printf("%c",'.');
	 			flag = true;
			 }
		 }
	 }
	

	for(int i = 1;i < pos;i++){
		if(str[i] == '.') continue;
		printf("%c",str[i]);
		if(exp == 0 && flag == false && i != pos-1) {
			printf("%c",'.');
			flag = true;
		}
		if(i != pos-1 && exp > 0) exp--;
	}
	
	//if(exp >= 0 && flag == false) exp++;
	if(exp > 0){
		for(int i = 1;i <= exp;i++){
			printf("%c",'0');
		}
	}
} 
