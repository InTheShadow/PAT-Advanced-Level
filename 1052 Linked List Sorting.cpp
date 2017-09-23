#include <cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct node{
	int address;
	int key;
	int next;
	bool flag;
};

vector<node> v;
map<int,int> a2i;

int cmp(node a,node b){
	if(a.flag == false || b.flag == false){
		return a.flag > b.flag;
	}
	else  {
		return a.key < b.key;
	}
}



int main(){
	int n,head;
	scanf("%d%d",&n,&head);
	v.resize(n);
	for(int i = 0;i < n;i++){
		scanf("%d %d %d",&v[i].address,&v[i].key,&v[i].next);
		a2i[v[i].address] = i; 
		v[i].flag = false;
	}
	int cnt = 0;
	for(int a = head; a != -1 ; a = v[a2i[a]].next){
		v[a2i[a]].flag = true;
		cnt++;
	}
	
	if(cnt == 0){
		printf("0 -1\n");
	}
	else{
		sort(v.begin(),v.end(),cmp);
		printf("%d %05d\n",cnt,v[0].address);
		for(int i = 0; i < cnt;i++){
			if(i == cnt - 1) printf("%05d %d -1\n",v[i].address,v[i].key);
			else printf("%05d %d %05d\n",v[i].address,v[i].key,v[i+1].address);
		}	
	}
	
}
