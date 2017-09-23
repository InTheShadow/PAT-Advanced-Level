#include<cstdio>
#include<set>
using namespace std;

const int maxn = 51;

set<int> st[maxn];
void compare(int x,int y){
	int totalNum = st[y].size(),sameNum = 0;
	for(set<int>::iterator it = st[x].begin(); it != st[x].end(); it++){
		if(st[y].find(*it) != st[y].end()) sameNum++;
		else totalNum++;
	}
	printf("%.1f%%\n",sameNum*100.0/totalNum);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		int m;
		scanf("%d",&m);
		for(int j = 0;j<m;j++){
			int k;
			scanf("%d",&k);
			st[i].insert(k);
		}
	}
	
	int m;
	scanf("%d",&m);
	for(int i = 1; i <= m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		compare(x,y);
	}
}
