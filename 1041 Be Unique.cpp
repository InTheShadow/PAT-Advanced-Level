#include<cstdio>
using namespace std;

int count[10001] = {0},bet[100001];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&bet[i]);
		count[bet[i]]++;
	}
	
	bool flag = false;
	for(int i = 0;i<n;i++){
		if(count[bet[i]] == 1) {
			printf("%d",bet[i]);
			flag = true; 
			break;
		}
	}
	if(!flag) printf("None");
}
