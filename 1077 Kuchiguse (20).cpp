#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s[101][257];

int main(){
	int n,minlen = 257;
	scanf("%d",&n);
	getchar();
	for(int i = 0;i < n;i++){
		gets(s[i]);
		int len = strlen(s[i]);
		reverse(s[i],s[i]+len);
		if(len < minlen) minlen = len;
	}
	
	int sameLen = 0;
	char sameChar;
	bool same;
	for(int i = 0;i < minlen;i++){
		sameChar = s[0][i];
		same = true;
		for(int j = 1;j < n;j++){
			if(s[j][i] != sameChar) {
				same = false;
				break;
			}
		}
		
		if(same) sameLen++;
		else{
			break;
		}	
	}
	if(sameLen == 0) printf("nai\n");
	else {
		for(int i = sameLen-1;i>=0;i--){
			printf("%c",s[0][i]);
		}
	}
	
}
