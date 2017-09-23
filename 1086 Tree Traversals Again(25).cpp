#include<cstdio>
#include<cstring> 
#include<stack>
using namespace std;
const int MAXN = 35;

int post[MAXN],pre[MAXN],in[MAXN];
stack<int> s; 
int n;
int postI = 0,preI = 0,inI = 0;
void getPost(int preL,int preR,int inL,int inR){
	if(preL > preR) return;
	int k;
	for(k = inL;k <= inR;k++){
		if(in[k] == pre[preL]) break;
	}
	int numLeft = k - inL;
	getPost(preL+1,preL+numLeft,inL,k-1);
	getPost(preL+numLeft+1,preR,k+1,inR);
	post[postI++] = pre[preL]; 
}

char temp[5];
int main(){
	scanf("%d",&n);
	for(int i = 0;i < 2*n;i++){
		scanf("%s",&temp);
		if(strcmp(temp,"Push") == 0){
			int x;
			scanf("%d",&x);
			s.push(x);
			pre[preI++] = x;
		}
		else {
			int x = s.top();
			s.pop();
			in[inI++] = x;
		}
	}
	getPost(0,preI-1,0,inI-1);
	for(int i = 0; i < n;i++){
		printf("%d",post[i]);
		if(i != n-1) printf(" ");
	}
	return 0;
}
