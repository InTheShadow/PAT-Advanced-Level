#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> v;
vector<bool> visited;
vector<int> tempRoot;
vector<int> root;
int maxDepth;

int dfs(int node,int depth){
	if(depth > maxDepth) {
		tempRoot.clear();
		tempRoot.push_back(node);
		maxDepth = depth;
	}
	
	else if(depth == maxDepth) {
		tempRoot.push_back(node);
	}
	
	visited[node] = true;
	for(int i = 0; i < v[node].size();i++){
		if(visited[v[node][i]] == false){
			dfs(v[node][i],depth+1);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	v.resize(n+1);
	visited.resize(n+1);
	fill(visited.begin(),visited.end(),false);
	for(int i = 0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int cnt = 0;
	maxDepth = 0;
	for(int i = 1;i<=n;i++){
		if(visited[i] == false){
			dfs(i,1);
			cnt++;
		}
	}
	
	for(int i = 0;i < tempRoot.size();i++){
		root.push_back(tempRoot[i]);
	}
	if(cnt >= 2){
		printf("Error: %d components",cnt);
	}
	else {
		tempRoot.clear();
		fill(visited.begin(),visited.end(),false);
		maxDepth = 0;
		dfs(root[0],1);
		for(int i = 0;i < tempRoot.size();i++){
			bool add = true;
			for(int j = 0;j < root.size();j++){
				if(root[j] == tempRoot[i]) {
					add = false;
					break;
				}
			}
			if(add) root.push_back(tempRoot[i]);
		}
		sort(root.begin(),root.end());
		for(int i = 0; i< root.size();i++){
			printf("%d\n",root[i]);
		}
	}
	
}
