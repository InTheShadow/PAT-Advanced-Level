#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main(){
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	for(int s1 = 0;s1 < k;s1++){
		int j = 1;
		stack<int> s;
		bool flag = true;
		for(int i = 0;i < n;i++){
			int num;
			scanf("%d",&num);
			if(s.size() != 0 && s.top() == num){
				s.pop();
			}
			else{
				if(num - j + 1 + s.size() > m || num < j) {
					flag = false;
					for(int s2 = i + 1;s2 < n;s2++) scanf("%d",&num);
					break;
				}
				else {
					for(int s2 = j;s2 <= num;s2++)s.push(s2);
					s.pop();
					j = num + 1;
				}
			}	
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
}
