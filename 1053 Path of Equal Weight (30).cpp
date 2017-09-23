#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct node{
	int w;
	vector<int> child;
};

vector<node> v;
vector<int> path;
int target;


void dfs(int index,int sum){
	if(sum > target) return;
	if(sum == target && v[index].child.size() == 0){
		for(int i = 0;i < path.size();i++){
		  printf("%d%c",v[path[i]].w, i!= path.size() -1?' ':'\n');
		}	
	}
	for(int i = 0; i<v[index].child.size();i++){
		int sub = v[index].child[i];
		path.push_back(sub);
		dfs(sub,sum+v[sub].w);
		path.pop_back();
	}
}

int cmp(int a,int b){
	return v[a].w > v[b].w;
}

int main(){
	int n,m;
	scanf("%d%d%d",&n,&m,&target);
	v.resize(n);
	for(int i = 0; i < n;i++){
		scanf("%d",&v[i].w);
	}
	
	for(int i = 0; i < m;i++){
		int k,index;
		scanf("%d %d",&index,&k);
		v[index].child.resize(k);
		for(int j = 0; j < k;j++){
			scanf("%d",&v[index].child[j]);
		}
		sort(v[index].child.begin(),v[index].child.end(),cmp);
	}
	path.push_back(0);
	dfs(0,v[0].w);
}
