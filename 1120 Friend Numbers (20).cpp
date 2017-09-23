#include<cstdio>
#include<set>
using namespace std;

const int MAXN = 10010;

set<int> fID;

int to_sum(int a){
	int sum = 0;
	while(a != 0){
		sum += a%10;
		a /= 10;
	}
	return sum;
}

int main(){
	int n,a,num = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&a);
		fID.insert(to_sum(a));
	}
	
	printf("%d\n",fID.size());
	
	for(set<int>::iterator it = fID.begin();it != fID.end();it++){
		if(it == fID.begin()) printf("%d",*it);
		else printf(" %d",*it);
	}
}
