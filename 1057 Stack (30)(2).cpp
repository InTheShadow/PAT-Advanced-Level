#include<cstring>
#include<stack>
#include<cmath>
#include<algorithm>
#define lowbit(n) ((n) & -(n))
using namespace std;

const int MAXN = 100010;

stack<int> s;
int c[MAXN] = {0};

void update(int a,int v){
	for(int i = a; i < MAXN;i += lowbit(i)){
		c[i] += v;
	}
}

int getSum(int a){
	int sum = 0;
	for(int i = a; i >= 1;i -= lowbit(i)){
		sum += c[i];
	}
	return sum;
}

void push(int a){
	s.push(a);
	update(a,1);
}

void pop(){
	if(s.size() == 0) printf("Invalid\n");
	else {
		int a = s.top();
		s.pop();
		update(a,-1);
		printf("%d\n",a);
	}
}

void peekMedian(){
	if(s.size() == 0) printf("Invalid\n");
	else {
		int k = s.size(),sum = 0;
		if(k%2 == 0) k /=2;
		else k = (k+1)/2;
		
		//binary
		int l = 1,r = MAXN-1,mid;
		while(l < r){
			mid = (l+r)/2;
			if(getSum(mid) >= k ){
				r = mid;
			}
			else {
				l = mid+1;
			}
		}
		
		printf("%d\n",l);
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
