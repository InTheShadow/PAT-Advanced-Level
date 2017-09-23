#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAXN 40010
#define MAXC 2510
using namespace std;

char name[MAXN][5];
vector<int> course[MAXC];
int cmp(int a,int b){
	return strcmp(name[a],name[b]) < 0;
}

int main(){
	int n,c;
	scanf("%d %d",&n,&c);
	for(int i = 1;i <= n;i++){
		int nc;
		scanf("%s%d",name[i],&nc);
		for(int j = 0;j<nc;j++){
			int x;
			scanf("%d",&x);
			course[x].push_back(i);
		}
	}
	
	for(int i = 1; i <= c;i++){
		sort(course[i].begin(),course[i].end(),cmp);
		printf("%d %d\n",i,course[i].size());
		for(int j = 0;j< course[i].size();j++){
			printf("%s\n",name[course[i][j]]);
		}
	}
} 
