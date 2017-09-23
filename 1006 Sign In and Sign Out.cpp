#include<iostream> 
#include<cstdio>
#include<limits.h>
using namespace std;
int main(){
	int n,mintime = INT_MAX,maxtime = INT_MIN;
	scanf("%d",&n);
	string unlocked,locked;
	for(int i = 0;i<n;i++){
		string temp;
		cin >> temp;
		int h1,m1,s1,h2,m2,s2;
		scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
		int in_time = h1*3600+m1*60+s1;
		int out_time = h2*3600+m2*60+s2;
		if(in_time < mintime){
			mintime = in_time;
			unlocked = temp;
		}
		
		if(out_time > maxtime){
			maxtime = out_time;
			locked = temp;
		}
		
	}
	cout << unlocked << " " << locked;
}
