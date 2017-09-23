#include<cstdio>
#include<cstring>
#define MAX 1000
using namespace std;

char str[MAX+1];
bool P[MAX+1][MAX+1];

int main(){
	gets(str);
	int len = strlen(str);
	int start = 0,step = 1;
	for(int i = 0; i < len;i++){
		P[i][i] = true;
		if(i < len - 1 && str[i] == str[i+1]){
			P[i][i+1] = true;
			start = i;
			step =2;
		}
	}
	
	
	for(int mlen = 3; mlen <= len;mlen++ ){
		for(int i = 0;i < len - mlen + 1;i++){
			int j = i + mlen -1;
			if(P[i+1][j-1] && str[i] == str[j]) {
				P[i][j] = true;
				start = i;
				step = mlen;
			}
		}
	}
	
	printf("%d",step);
}
