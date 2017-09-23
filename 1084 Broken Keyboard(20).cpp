#include<cstring>
#include<iostream>
using namespace std;

int count[128] = {0};
char str1[100], str2[100];
int main(){
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	char c;
	for(int i= 0; i < len1 ;i++){
		c = str1[i];
		if(c <= 'z' && c >= 'a') c = c + 'A' - 'a';
		if(count[c] == 0 ) count[c] = 1;
	}
	
	for(int i = 0; i < len2; i++){
		c = str2[i];
		if(c <= 'z' && c >= 'a') c = c + 'A' - 'a';
		if(count[c] == 1) count[c] = 2;
	}
	
	for(int i = 0;i < len1;i++){
		c = str1[i];
		if(c <= 'z' && c >= 'a') c = c + 'A' - 'a';
		if(count[c] == 1) {
			printf("%c",c);
			count[c] = 0;
		}
	}
}
