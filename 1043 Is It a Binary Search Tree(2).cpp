#include<cstdio>
#include<vector>
using namespace std;

bool isMirror;
vector<int> pre;
vector<int> post;

void getPost(int root,int tail){
	if(root > tail) return ;
	int i = root+1,j = tail;
	if(!isMirror) {
		while(i <= tail && pre[i] >= pre[root]) i++;
		while(j > root&& pre[j] < pre[root]) j--;
	}
	else {
		while(i <= tail && pre[i] < pre[root] ) i++;
		while(j > root && pre[j] >= pre[root] ) j--;
	}
	if(i - j !=1) return;
	getPost(root+1,j);
	getPost(i,tail);
	post.push_back(pre[root]);
}

int main(){
	int n;
	scanf("%d",&n);
	pre.resize(n);
	for(int i = 0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	isMirror = true;
	getPost(0,n-1);
	if(post.size() != n){
		isMirror = false;
		post.clear();
		getPost(0,n-1);
	}
	
	if(post.size() == n){
		printf("YES\n%d",post[0]);
		for(int i = 1;i < n;i++){
			printf(" %d",post[i]);
		}
	}
	
	else {
		printf("NO\n");
	}
}