#include<cstdio>

int main(){
	int ans ,count = 0,n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i < n*m;i++){
		int num;
		scanf("%d",&num);
		if(count == 0) ans = num;
		if(num == ans) count++;
		else count--;
	}
	printf("%d\n",ans);
	return 0;
}
