#include<cstdio>
#include<vector>
using namespace std;

int main(){
	int m,n;
	scanf("%d",&m);
	vector<long int> v1(m);
	for(int i = 0;i<m;i++){
		scanf("%ld",&v1[i]);
	}
	scanf("%d",&n);
	vector<long int>v2(n);
	for(int i = 0;i<n;i++){
		scanf("%ld",&v2[i]);
	}
	
	int cnt = (m+n-1)/2,p = 0,q = 0;
	while(cnt){
		while(p < m && q < n && v1[p] < v2[q] && cnt){
			p++;
			cnt--;
		}
		while(p < m&& q < n&& v1[p] >= v2[q] && cnt){
			q++;
			cnt--;
		}
		while(p < m && q>=n && cnt){
			p++;
			cnt--;
		}
		while(q < n && p >= m && cnt){
			q++;
			cnt--; 
		}
	}
	
	long int ans;
	if(p < m && q < n){
		ans = v1[p] < v2[q] ? v1[p] : v2[q];  
	}
	else ans = p < m ? v1[p] : v2[q];
	printf("%ld",ans);
}
