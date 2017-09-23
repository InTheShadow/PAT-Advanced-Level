#include<iostream>
#define DOWNTIME 4
#define UPTIME 6
#define STOPTIME 5
using namespace std;

int main(){
	int pre = 0,p,totalTime = 0;
	cin >> p;
	while(cin >> p){
		int moveFloor = p - pre;
		totalTime+=STOPTIME; 
		if(moveFloor < 0) totalTime+=(-moveFloor)*DOWNTIME;
		else totalTime+=(moveFloor)*UPTIME;
		pre = p; 
	}
	
	cout << totalTime;
}
