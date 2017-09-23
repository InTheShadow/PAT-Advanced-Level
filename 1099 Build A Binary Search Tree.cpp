#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct node{
	string str;
	int left,right;
};

vector<node> v;

int root;
string s;
void dfs(int index){
	bool needAdd = ((v[index].right != -1) && (index != root));
	if(needAdd) s += "("; 
	if(v[index].left != -1) {
		dfs(v[index].left);	
	}
	
	s += v[index].str;
	
	if(v[index].right != -1){
		dfs(v[index].right);
	}
	if(needAdd) s += ")"; 
}

int main(){
	int n;
	scanf("%d",&n);
	v.resize(n+1);
	vector<bool> visited(n+1,false);
	for(int i = 1;i <= n;i++){
		cin >> v[i].str;
		scanf("%d%d",&v[i].left,&v[i].right);
		if(v[i].left != -1) visited[v[i].left] = true;
		if(v[i].right != -1) visited[v[i].right] = true;
	}
	root = 1;
	while(visited[root] == true) root++;
	s = "";
	dfs(root);
	cout << s << endl;
}
