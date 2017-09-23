#include<cstring>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN = 100010;

const int MAXL = 316;

const int MAXSQ = MAXL;

stack<int> s;
int table[MAXN] = {0};
int block[MAXSQ] = {0};

void push(int a){
	s.push(a);
	table[a]++;
	block[a/MAXL]++;
}

void pop(){
	if(s.size() == 0) printf("Invalid\n");
	else {
		int a = s.top();
		s.pop();
		table[a]--;
		block[a/MAXL]--;
		printf("%d\n",a);
	}
}

void peekMedian(){
	if(s.size() == 0) printf("Invalid\n");
	else {
		int k = s.size(),sum = 0,i = 0, j;
		if(k%2 == 0) k /=2;
		else k = (k+1)/2;
		for(i = 0; i < MAXSQ;i++){
			if(sum + block[i] >= k) break;
			sum += block[i];
		} 
		for(j = i*MAXL; j < (i+1)*MAXL;j++){
			if(sum + table[j] >= k) break;
			sum += table[j];
		}
		printf("%d\n",j);
	} 
}

char temp[25],res[25];
int b;
void judge(char a[]){
	if(strcmp(a,"Pop") == 0) pop();
	else if(strcmp(a,"PeekMedian") == 0)  peekMedian();
	else {
		sscanf(temp,"%s %d",&res,&b);
		if(strcmp(res,"Push") == 0) push(b);
		else printf("Invalid\n");
	}
}

int main(){
	int n;
	scanf("%d",&n);
	getchar();
	for(int i = 0; i < n;i++){
		gets(temp);
		judge(temp);
	}
}
