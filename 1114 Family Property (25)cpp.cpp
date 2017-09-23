#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 10010;

int father[MAXN];
struct family{
	int minID;
	double areas;
	double sets;
	int num;
}fams[MAXN];

int findFather(int x){
	int a = x;
	while(x != father[x]) {
		x = father[x];
	}
	
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

int Union(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb) {
		father[fb] = fa;
		fams[fa].num += fams[fb].num;
		if(fams[fb].minID < fams[fa].minID) 
			fams[fa].minID = fams[fb].minID;
		fams[fa].sets += fams[fb].sets;
		fams[fa].areas += fams[fb].areas;
		
		fams[fb].areas = 0.0;
		fams[fb].sets = 0.0;
		fams[fb].minID = fb;
		fams[fb].num = 1;
	}
	
}

int init(){
	for(int i = 0;i < MAXN;i++){
		father[i] = i;
		fams[i].areas = 0.0;
		fams[i].sets = 0.0;
		fams[i].minID = i;
		fams[i].num = 1;
	}
}

bool cmp(family a,family b){
	if(a.areas != b.areas) return a.areas > b.areas;
	else return a.minID < b.minID;
}

int main(){
	int n;
	scanf("%d",&n);
	init();
	for(int i = 0;i < n;i++){
		int id,fa,ma,k;
		scanf("%d%d%d%d",&id,&fa,&ma,&k);
		int rootID = findFather(id);
		if(fa != -1) Union(rootID,fa);
		if(ma != -1)Union(rootID,ma);
		for(int i = 0; i < k;i++){
			int child;
			scanf("%d",&child);
			if(child != -1) Union(rootID,child);
		}
		
		int sets,areas;
		scanf("%d %d",&sets,&areas);
		fams[rootID].sets += sets;
		fams[rootID].areas += areas;
	}
	
	for(int i = 0;i < MAXN;i++){
		if(fams[i].areas == 0.0) continue;
		fams[i].sets = fams[i].sets/fams[i].num;
		fams[i].areas = fams[i].areas/fams[i].num;
	}
	sort(fams,fams+MAXN,cmp);
	
	int num = 0;
	while(fams[num].areas != 0.0) num++;
	
	printf("%d\n",num);
	for(int i = 0;i < num;i++){
		printf("%04d %d %.3f %.3f\n",fams[i].minID,fams[i].num,fams[i].sets,fams[i].areas);
	}
}



