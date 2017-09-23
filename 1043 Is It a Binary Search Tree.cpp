#include<iostream>
#include<vector>
using namespace std;

vector<int> post;
vector<int> pre;
int mirror = -1;
bool check(int low,int high){
	if(low >= high){
		post.push_back(pre[low]);
		return true;
	}
	if(mirror == -1){
		if(pre[low+1] < pre[low]) mirror = 0;
		else mirror = 1;
	}
	
	
	int next = low;
	
	for(int i = low+1;i<=high;i++){
		if(mirror == 0 && pre[i] >= pre[low]){
			next = i;
			break;
		}
		else if(mirror == 1 && pre[i] < pre[low]){
			next = i;
			break;
		}
	}
	
	bool left = true,right = true;
	if(next == low || next > low + 1){
		for(int i = low+1;i<=next - 1;i++){
			if(mirror == 0 && pre[i] >= pre[low]) return false;
			else if(mirror == 1 && pre[i] < pre[low]) return false;
		} 
		
		if(next == low ) left = check(low+1,high);
		else if(next > low + 1) left = check(low + 1,next - 1);
	}
	
	if(next == low + 1 || next > low + 1){
		for(int i = next;i<=high;i++){
			if(mirror == 0 && pre[i] < pre[low]) return false;
			else if(mirror == 1 && pre[i] >= pre[low]) return false;
		}
		right = check(next,high);
	}
	post.push_back(pre[low]);
	return left&&right;
}

int main(){
	int n;
	scanf("%d",&n);
	pre.resize(n);
	for(int i = 0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	mirror = -1;
	bool OK = check(0,n-1);
	if(OK){
		printf("YES\n");
		for(int i = 0;i<n;i++){
			if(i == n-1) printf("%d",post[i]);
			else printf("%d ",post[i]);
		}
	}
	
	else printf("NO\n");
}
