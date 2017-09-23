#include<cstdio>
#include<algorithm>
using namespace std;
int post[35],in[35];
struct node{
	int depth;
	int root;
	int data;
}level[35];
void getLevel(int root,int start,int end,int depth){
	int i;
	while(i < end && in[i] != post[root]) i++;
	level[i].depth = depth;
	level[i].data = post[root];
	level[i].root = root;
	if(i != start){
		getLevel(root-end+i-1,start,i-1,depth+1);
	}
	if(i != end){
		getLevel(root-1,i+1,end,depth+1);
	} 
}
int cmp(node a,node b) {
	if(a.depth < b.depth) return true;
	else if(a.depth > b.depth) return false;
	else return a.root < b.root;
}

int main(){
	for(int i = 0;i<35;i++){
		level[i].depth = -1;
	}
	fill(post,post+35,-1);
	fill(in,in+35,-1);
	
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i = 0;i<n;i++){
		scanf("%d",&in[i]);
	}
	getLevel(n-1,0,n-1,1);
	sort(level,level+35,cmp);
	for(int i = 0;i<35;i++){
		if(level[i].depth != -1){
			if(i == 34) printf("%d",level[i].data);
			else printf("%d ",level[i].data);
		} 
	}
}
