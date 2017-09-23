#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 15;

int N;
char temp[2];
bool visited[MAXN] = {false};
struct Node{
	int left;
	int right; 
}nodes[MAXN];

void levelOrder(int root){
	int levelI = 0;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		printf("%d",top);
		if(levelI != N-1) printf(" ");
		levelI++;
		if(levelI == N) break;
		if(nodes[top].right != -1) q.push(nodes[top].right); 
		if(nodes[top].left != -1)  q.push(nodes[top].left);
	}
}

int inI = 0;
void inOrder(int root){
	if(nodes[root].right != -1) inOrder(nodes[root].right); 
	printf("%d",root);
	if(inI != N-1) printf(" ");
	inI++;
	if(inI == N) return;
	if(nodes[root].left != -1) inOrder(nodes[root].left);
 }
 
int getValue(char temp[]){
	if(strcmp(temp,"-") == 0) return -1;
	else return temp[0] - '0';
}
 
 int main(){
 	scanf("%d",&N);
 	for(int i = 0; i < N;i++){
 		scanf("%s",&temp);
 		nodes[i].left = getValue(temp);
 		if(nodes[i].left != -1) visited[nodes[i].left] = true;
 		
 		scanf("%s",&temp);
 		nodes[i].right = getValue(temp);
 		if(nodes[i].right != -1) visited[nodes[i].right] = true;
	 }
	 int root = 0;
	 while(visited[root] == true) root++;
	 levelOrder(root);
	 printf("\n");
	 inOrder(root);
	 printf("\n");
 }
 
 
