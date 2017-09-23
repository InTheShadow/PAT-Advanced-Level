#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define CLOSETIME 540
using namespace std;


struct  Window{
	int popTime;
	queue<int> q;
}; 

struct Customer{
	int startTime;
	int endTime;
	int wasteTime; 
	bool isNext;
};

int findBestWindow(vector<Window> windows){
	int best = 0;
	for(int i = 1;i<windows.size();i++){
		if(windows[i].q.size() < windows[best].q.size()) best = i;
	}
	return best;
}
int currentTime;
void refreshCurrentTime(vector<Window> windows){
	int tempTime = CLOSETIME+1;
	for(int i = 0; i< windows.size();i++){
		int popTime = windows[i].popTime;
		if(popTime < tempTime){
			tempTime = popTime;
		}  
	}
	currentTime = tempTime;
}



int main(){
	//read n,m,k,q
	int n,m,k,q;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	//read time for custormer
	vector<Customer> customers(k+1);

	for(int i = 1;i<=k;i++){
		scanf("%d",&customers[i].wasteTime);
		customers[i].startTime = 0;
		customers[i].endTime = -1;
		customers[i].isNext = false;
	}
	 vector<Window> windows(n);
	 for(int i = 0;i <n;i++) {
	 	windows[i].popTime = 0;
	 }
	int i = 1;
	currentTime = 0;
	while(true){
		//put in all custormer in the queue
		while(i<=k){
			int best = findBestWindow(windows);
			if(windows[best].q.size() == m) break;
			windows[best].q.push(i);
			i++;
		}

		//compute poptime for every queue
		for(int j = 0;j<n;j++) {
			if(windows[j].q.size() == 0) continue;
			int index = windows[j].q.front();
			if(customers[index].isNext == false) {
				customers[index].isNext = true;
				windows[j].popTime = currentTime + customers[index].wasteTime;
			}
		}
		
		//pop customers and get res
		refreshCurrentTime(windows);
		if(currentTime > CLOSETIME) break;
		
		for(int j = 0;j<n;j++){
			if(windows[j].popTime == currentTime) {
				customers[windows[j].q.front()].endTime = currentTime;
				windows[j].popTime = CLOSETIME+2;
				windows[j].q.pop();	
			}
		}
		
	}
	//print 
	for(int i = 0; i < q;i++){
		int d;
		scanf("%d",&d); 
		if(customers[d].endTime == -1 ) printf("Sorry\n");
		else printf("%02d:%02d\n",customers[d].endTime/60+8,customers[d].endTime%60);
	}
}


