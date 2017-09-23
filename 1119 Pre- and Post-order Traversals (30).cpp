#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 35;

vector<int> inOrder;
int pre[MAXN],post[MAXN];

bool unique = true;
void getIn(int preL,int preH,int postL,int postH){
	if(preL > preH) return;
	if(preL == preH){
		inOrder.push_back(pre[preL]);
		return;
	} 
	if(preH-preL == 1) {
		if(pre[preL] != post[postL]){
			unique = false;
		}	
	}
	int leftR = pre[preL+1];
	int j = postL;
	while(post[j] != leftR) j++;
	int leftN = j - postL+1;
	getIn(preL+1,preL+leftN,postL,j);
	inOrder.push_back(pre[preL]);
	getIn(preL+leftN+1,preH,j+1,postH-1);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i = 0;i < n;i++){
		scanf("%d",&post[i]);
	}
	getIn(0,n-1,0,n-1);
	
	if(unique) printf("Yes\n");
	else printf("No\n");
	for(int i = 0; i < n;i++){
		printf("%d",inOrder[i]);
		if(i != n-1) printf(" ");
	}
	printf("\n");
}
