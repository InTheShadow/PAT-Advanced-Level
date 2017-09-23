#include<cstdio>
#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXV = 10010;
const int INF = 0x3fffffff;
struct Edge{
	int next;
	int line;
}temp;

vector<Edge> s[MAXV];
bool vis[MAXV] = {false};
vector<int> tempTran,tran,tempLine,line;
int des,minNum;

void dfs(int index,int number,int lLine){
	if(index == des){
		tempTran.push_back(index);
		if(number < minNum){
			minNum = number;
			tran = tempTran; 
			line = tempLine; 
		}
		else if(number == minNum && tempTran.size() < tran.size()){
			tran = tempTran;
			line = tempLine;
		}
		tempTran.pop_back();
		return;
	}
	
	for(int i = 0; i < s[index].size();i++){
		Edge nowEdge = s[index][i];
		if(vis[nowEdge.next] == true) continue;
		int newlLine = lLine;
		if(nowEdge.line != lLine){
			tempTran.push_back(index);
			newlLine = nowEdge.line;
			tempLine.push_back(newlLine);
		}
		vis[nowEdge.next] = true;
		dfs(nowEdge.next,number+1,newlLine);
		vis[nowEdge.next] = false;
		if(nowEdge.line != lLine){
			tempTran.pop_back();
			tempLine.pop_back();
		}
	}
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		int k,pre;
		scanf("%d",&k);
		scanf("%d",&pre);
		for(int j = 1; j < k;j++){
			int p;
			scanf("%d",&p);
			temp.line = i;
			temp.next = p;
			s[pre].push_back(temp);
			temp.line = i;
			temp.next = pre;
			s[p].push_back(temp);
			pre = p;
		}
	}
	
	int k;
	scanf("%d",&k);
	for(int i = 0;i < k;i++){
		int sta;
		scanf("%d%d",&sta,&des);
		tran.clear();
		line.clear();
		minNum = INF;
		dfs(sta,0,0);
		printf("%d\n",minNum);
		for(int i = 0;i < tran.size() -1;i++){
			printf("Take Line#%d from %04d to %04d.\n",line[i],tran[i],tran[i+1]);
		}
	}
}
