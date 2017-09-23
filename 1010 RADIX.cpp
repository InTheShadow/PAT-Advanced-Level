#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int map[128];

long long convertToTen(char a[],long long radix){
	long long ans = 0;
	for(int i = 0;i< strlen(a);i++){
		ans = ans*radix + (long long)(map[a[i]]);
	}
	return ans;
} 

int cmp(char n2[], long long radix, long long t){
	long long num = convertToTen(n2,radix);
	if(num < 0 ) return 1;
	if(num < t) return -1;
	return (t == num) ? 0:1; 
}

long long binarySearch(char n2[], long long left, long long right,long long t){
	long long mid;
	while(left<=right){
		mid = (left+right)/2;
		int flag = cmp(n2,mid,t);
		if(flag == 0 ) return mid;
		else if(flag < 0 ) left = mid+1;
		else right = mid-1;
	}
	return -1;
}

int findLargestDigit(char n2[]){
	int ans = -1,len = strlen(n2);
	for(int i = 0;i < len;i++){
		if(map[n2[i]] > ans) ans = map[n2[i]];
	}	
	return ans+1;
}

int main(){
	char n1[11],n2[11];
	long long radix;
	int tag;
	//table reset 
	for(char c = '0';c <= '9';c++) map[c] = c-'0';
	for(char c = 'a';c <= 'z';c++) map[c] = c-'a'+10;
	//scanf 
	scanf("%s%s%d%lld",&n1,&n2,&tag,&radix);
	if(tag == 2) swap(n1,n2);
	//compute 
	long long t = convertToTen(n1,radix);
	long long low = findLargestDigit(n2);
	long long high = max(low,t)+1;
	long long ans = binarySearch(n2,low,high,t);
	if(ans == -1) printf("Impossible");
	else printf("%lld",ans);
}
















