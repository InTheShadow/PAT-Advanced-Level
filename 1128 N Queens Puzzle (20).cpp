#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n;i++){
		int m;
		bool flag = true;
		scanf("%d",&m);
		for(int j = 0; j < m;j++){
			scanf("%d",&a[j]);
			for(int t = 0; t < j;t++){
				if(flag == false) break;
				if(abs(a[j] - a[t]) == abs(j - t) || a[j] == a[t]) {
					flag = false;
					break;
				}
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
}
