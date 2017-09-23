#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1010;

struct Node{
	int data;
}nodes[MAXN];

int in[MAXN];
int N;

int index = 0;
void getData(int root){
	if(root > N) return; 
	getData(2*root);
	nodes[root].data = in[index++];
	getData(2*root+1);
}

int main(){
	scanf("%d",&N);
	for(int i = 0;i < N;i++){
		scanf("%d",&in[i]);
	}
	sort(in,in+N);
	getData(1);
	for(int i = 1;i <= N;i++){
		printf("%d",nodes[i].data);
		if(i != N) printf(" ");
	}
}

 
