#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>p,c;
int nc,np,profit;

int main(){
	scanf("%d",&nc);
	c.resize(nc);
	for(int i = 0;i < nc;i++){
		scanf("%d",&c[i]);
	}
	scanf("%d",&np);
	p.resize(np);
	for(int i = 0;i < np;i++){
		scanf("%d",&p[i]);
	}
	sort(c.begin(),c.end());
	sort(p.begin(),p.end());
	
	int i = 0, j = 0;
	profit = 0;
	while(c[i] < 0 && p[j] < 0 && i < nc && j < np) {
		profit += c[i] * p[j];
		i++;
		j++;
	}
	
	i = nc -1;
	j = np - 1;
	while(c[i] > 0 && p[j] > 0 && i >= 0 && j >= 0){
		profit += c[i]*p[j];
		i--;
		j--;
	}
	
	printf("%d",profit);
}
