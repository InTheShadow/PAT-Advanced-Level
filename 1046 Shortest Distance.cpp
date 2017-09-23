#include<cstdio>
#include<vector>
using namespace std;
vector<int> dis;

int main(){
	int n,sum=0,m,num;
	scanf("%d",&n);
	dis.resize(n+1);
	for(int i = 1;i<=n;i++){
		scanf("%d",&num);
		dis[i] = sum;
		sum += num;
	}
	
	scanf("%d",&m);
	for(int i = 1;i <=m ;i++){
		int left,right;
		scanf("%d%d",&left,&right);
		if(left > right){
			int temp = left;
			left = right;
			right = temp;
		}
		printf("%d\n",min(dis[right]-dis[left],sum - dis[right] +  dis[left]));
	}
}
