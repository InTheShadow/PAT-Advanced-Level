#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define CLOSETIME 18*60*60
#define OPENTIME 8*60*60
using namespace std;

struct Customer{
	int comeTime;
	int wasteTime;
}; //second

bool cmp(Customer a,Customer b) {return a.comeTime < b.comeTime;}

int main(){
	//scanf
	int n,k; 
	scanf("%d%d",&n,&k); 
	vector<Customer> customers;
	int hour,minute,second,wasteTime;
	for(int i = 0;i<n;i++){
		scanf("%d:%d:%d %d",&hour,&minute,&second,&wasteTime);
		if(hour == 17 && (minute != 0 ||second != 0)) {
			continue;
		}
		if(hour > 17) continue;
		if(wasteTime > 60) wasteTime = 60; 
		Customer temp = {hour*3600+minute*60+second,wasteTime*60};
		customers.push_back(temp);
	}
	//sort and init
	sort(customers.begin(),customers.end(),cmp);
	vector<int> windowEndTime(k);
	queue<int> line;
	for(int i = 0;i < k;i++) windowEndTime[i] = CLOSETIME+1;

	//change currentTime
	int currentTime = 0; 
	int customerIndex = 0;
	int totalTime = 0;
	bool opened = false;
	while(true) {
		//change current Time ¡¢pop window or enqueue 
		int minTime = CLOSETIME+1;
		int windowIndex = -1;
		for(int i = 0;i <k;i++){
			if(windowEndTime[i] < minTime) {
				minTime = windowEndTime[i];
				windowIndex = i;
			}
		} 
		if(customerIndex < customers.size() && customers[customerIndex].comeTime < minTime){
			minTime = customers[customerIndex].comeTime;
			windowIndex = -1;
		}
		if(minTime > OPENTIME && !opened) {
			minTime = OPENTIME;
		}

		currentTime = minTime;
		if(currentTime >= CLOSETIME+1) break;
		if(currentTime == OPENTIME) {
			opened = true;
			if(customers[customerIndex].comeTime == OPENTIME) {
				line.push(customerIndex);
				customerIndex++;
			}
		}
		else if(windowIndex != -1){
			windowEndTime[windowIndex] = CLOSETIME+1;
		}
		else{
			line.push(customerIndex);
			customerIndex++;
		}
		
		//toWindow
		if(currentTime >= OPENTIME ){
			for(int i = 0;i <k;i++){
				if(line.empty()) break;
				if(windowEndTime[i] == CLOSETIME+1) {
					windowEndTime[i] = currentTime+customers[line.front()].wasteTime;
					totalTime += (currentTime - customers[line.front()].comeTime);
					line.pop();
				}
			} 			
		}	
	}
	//printf 
	if(customers.size() == 0) printf("0.0");
	else printf("%.1f",totalTime*1.0/(customers.size()*60.0));
	
}
