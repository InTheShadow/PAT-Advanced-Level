#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
enum Judge{sa,no,fo,sm};
struct node{
	int id;
	int T;
	int V;
	int total;
	Judge j;
};

node temp;
vector<node> nodes;
vector<int> v;
int L,H,N;

void judge(node& a){
	a.total = a.T + a.V;
	if(a.T >= H && a.V >= H) a.j = sa;
	else if(a.T < H && a.V >= H) a.j = no;
	else if(a.T < H && a.V >= a.T) a.j = fo;
	else a.j = sm;
}; 

bool cmp(int ai,int bi){
	node a = nodes[ai], b = nodes[bi];
	if(a.j != b.j) return a.j < b.j;
	else if(a.total != b.total) return a.total > b.total;
	else if(a.V != b.V) return a.V > b.V;
	else return a.id < b.id;
}



int main(){
	scanf("%d%d%d",&N,&L,&H);
	int index = 0;
	for(int i = 0;i < N;i++){
		scanf("%d%d%d",&temp.id,&temp.V,&temp.T);
		if(temp.V >= L && temp.T >= L){
			judge(temp);
			nodes.push_back(temp);
			v.push_back(index);
			index++;
		}
	}
	
	sort(v.begin(),v.end(),cmp);
	printf("%d\n",index);
	for(int i = 0; i < index;i++){
		temp = nodes[v[i]];
		printf("%08d %d %d\n",temp.id,temp.V,temp.T);
	}
}
