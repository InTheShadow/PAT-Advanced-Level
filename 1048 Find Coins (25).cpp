#include<cstdio>
using namespace std;
int count[1001] = {0};
int main(){
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i = 0;i < n;i++){
		int x; 
		scanf("%d",&x);
		count[x] += 1;
	}
	
	for(int i = 1; i < m;i++){
		if(i == m-i){
			if(count[i] >= 2) {
				printf("%d %d",i,i);
				return 0;
			}
		} 
		else if(count[i] && count[m-i]) {
			printf("%d %d",i,m-i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
} 
