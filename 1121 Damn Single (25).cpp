#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

map<int,int> cp;
map<int,int> ind;

struct node{
	int id;
	bool cped;
}nodes[10010];

bool cmp(node a,node b){
	if(a.cped != b.cped) return a.cped < b.cped;
	else return a.id < b.id;
}

int main(){
	int n,m;
	scanf("%d",&n);
	for(int i= 0;i < n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		cp[a] = b;
		cp[b] = a;
	} 
	
	scanf("%d",&m);
	int num = 0;
	for(int i = 0; i < m;i++){
		int id;
		scanf("%d",&id);
		nodes[i].id = id;
		nodes[i].cped = false;
		ind[id] = i;
		if(cp.count(id) != 0 && ind.count(cp[id]) != 0){
			nodes[ind[cp[id]]].cped = true;
			nodes[i].cped = true;
			num -= 2;
		} 
		num++;
	}
	
	sort(nodes,nodes+m,cmp);
	printf("%d\n",num);
	for(int i = 0;i < num;i++){
		printf("%05d",nodes[i].id);
		if(i != num-1) printf(" ");
	} 
	
}
