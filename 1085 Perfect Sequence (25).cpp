#include<cstdio>
#include<algorithm>
using namespace std;

int num[100010];

int main(){
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i = 0;i < n;i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	int i = 0,j = 0,count = 0;
	while(i < n && j < n){
		while(j < n && num[j] <=(long long)(num[i]) * p) {
			count = max(count,j-i+1);
			j++;
		}
		i++;
	}
	
	printf("%d\n",count);
}
