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

int minDepth = MAXN;
int num = 0;

void dfs(int index,int depth){
	if(nodes[index].child.size() == 0){
		if(depth < minDepth) {
			minDepth = depth;
			num = 1;
		}
		else if(depth == minDepth){
			num++;
		}
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
		if(k == 0) ;
		else {
			nodes[i].child.resize(k);
			for(int j = 0; j < k;j++){
				scanf("%d",&nodes[i].child[j]);
			}
		}
	}
	dfs(0,0);
	printf("%.4f %d\n",P0*pow(1+r,minDepth),num);
}
