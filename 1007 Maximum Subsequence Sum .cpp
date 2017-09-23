#include <cstdio>'
#include <vector>
using namespace std;

int main(){
	int n,flag = 0,sum = -1,temp = 0,left = 0,right = 0,tempIndex = 0;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		scanf("%d",&v[i]);
		if(v[i] >= 0) flag = 1;
		temp = temp+v[i];
		if(temp > sum){
			sum = temp;
			right = i;
			left = tempIndex;
		}
		if(temp < 0){
			temp = 0;
			tempIndex = i + 1;
		}
	}
	
	if(flag == 0) printf("%d %d %d",0,v[0],v[n-1]);
	else printf("%d %d %d",sum,v[left],v[right]);
	return 0;
} 
