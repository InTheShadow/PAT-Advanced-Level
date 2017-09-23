#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

const int MAXN = 100010;
int N;
double P0,r;

struct Node{
	vector<int> child;
}nodes[MAXN];

int maxDepth = 0;
int num = 0;

void dfs(int index,int depth){
	if(nodes[index].child.size() == 0){
		if(depth > maxDepth) {
			maxDepth = depth;
			num = 1;
		}
		else if(depth == maxDepth){
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
		int x ;
		scanf("%d",&x);
		nodes[x+1].child.push_back(i+1);
	}
	dfs(0,0);
	printf("%.2f %d\n",P0*pow(1+r,maxDepth-1),num);
}
