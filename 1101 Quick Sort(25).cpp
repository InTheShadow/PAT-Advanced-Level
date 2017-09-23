#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
const int inf = 0x3fffffff;

int a[maxn],leftMax[maxn],rightMin[maxn],ans[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i< n;i++){
		scanf("%d",&a[i]);
	}
	
	leftMax[0] = 0;
	for(int i = 1; i < n;i++){
		leftMax[i] = max(leftMax[i-1],a[i-1]);
	}
	
	rightMin[n-1] = inf;
	for(int i = n-2; i >= 0;i--){
		rightMin[i] = min(rightMin[i+1],a[i+1]);
	}
	
	int num = 0;
	for(int i = 0; i < n;i++){
		if(a[i] > leftMax[i] && a[i] < rightMin[i]) {
			ans[num++] = a[i];
		}
	}
	printf("%d\n",num);
	for(int i = 0; i < num;i++){
		if(i != num-1)printf("%d ",ans[i]);
		else printf("%d",ans[i]);
	}
	printf("\n");
}
