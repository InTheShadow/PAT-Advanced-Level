#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

const int MAXN = 100010;
int N;
double P0,r;

struct Node{
	double data;
	vector<int> child;
}nodes[MAXN];

double total = 0.0;

void dfs(int index,int depth){
	if(nodes[index].child.size() == 0){
		total += nodes[index].data*P0*pow(1.0+r,depth);
		return;
	}
	for(int i = 0; i < nodes[index].child.size();i++){
		dfs(nodes[index].child[i],depth+1);
	}
}

int main(){
	scanf("%d %lf %lf",&N,&P0,&r);
	r /= 100.0;
	for(int i = 0; i < N;i++){
		int k;
		scanf("%d",&k);
		if(k == 0) {
			scanf("%lf",&nodes[i].data);
		}
		else {
			nodes[i].child.resize(k);
			for(int j = 0; j < k;j++){
				scanf("%d",&nodes[i].child[j]);
			}
		}
	}
	dfs(0,0);
	printf("%.1f\n",total);
}

