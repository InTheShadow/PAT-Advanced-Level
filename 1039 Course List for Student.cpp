#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 26*26*26*10+1;

int hashTo(char* name){
	return (name[0] - 'A')*26*26*10+
		(name[1]-'A')*26*10+
		(name[2]-'A')*10+
		(name[3] -'0');
}

vector<int> v[maxn];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0; i< m;i++){
		int ni,mi;
		scanf("%d %d",&mi,&ni);
		for(int i = 0;i < ni;i++){
			char name[5];
			scanf("%s",name);
			v[hashTo(name)].push_back(mi);
		}
	}
	
	for(int i = 0; i < n;i++){
		char name[5];
		scanf("%s",name);
		int add = hashTo(name);
		sort(v[add].begin(),v[add].end());
		printf("%s %d",name,v[add].size());
		for(int j = 0; j < v[add].size();j++){
			printf(" %d",v[add][j]);
		}
		printf("\n");
	}
	return 0;
}
