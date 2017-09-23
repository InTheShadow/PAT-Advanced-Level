#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 100010;
const int MOD = 1000000007;
int leftPNum[MAXN] = {0} ;
char str[MAXN];

int main(){
	gets(str);
	int len = strlen(str);
	for(int i = 0; i < len;i++){
		if(i > 0) leftPNum[i] = leftPNum[i-1];
		if(str[i] == 'P') leftPNum[i]++;
	}	
	
	int sum = 0,rightTNum = 0;
	for(int i = len -1 ;i >= 0;i--){
		if(str[i] == 'T') rightTNum++;
		else if(str[i] == 'A'){
			sum = (sum + rightTNum*leftPNum[i])%MOD;
		}
	}
	
	printf("%d\n",sum);
	return 0;
}
