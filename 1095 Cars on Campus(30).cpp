#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 10010;
struct Car{
	char id[8];
	int time;
	bool in;
} all[maxn],valid[maxn];

bool cmpByIdAndTime(Car a,Car b){
	if(strcmp(a.id,b.id)) return strcmp(a.id,b.id) < 0;
	else return a.time < b.time;
}

bool cmpByTime(Car a,Car b){
	return a.time < b.time;
}

map<string,int>  parkTime; 

int timeToInt(int hh,int mm,int ss) {
	return hh*3600+mm*60+ss;
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	
	char status[4];
	int hh,mm,ss;
	for(int i = 0; i < n;i++){
		scanf("%s %d:%d:%d %s",&all[i].id,&hh,&mm,&ss,&status);
		all[i].time = timeToInt(hh,mm,ss);
		all[i].in = (strcmp(status,"in") == 0);
	}
	
	sort(all,all+n,cmpByIdAndTime);
	int index = 0;
	int maxTime = -1;
	for(int i = 0;i < n - 1;i++){
		if(!strcmp(all[i].id,all[i+1].id)
		&& all[i].in && !all[i+1].in){
			valid[index++] = all[i];
			valid[index++] = all[i+1];
			int inTime = all[i+1].time - all[i].time;
			if(parkTime.count(all[i].id) == 0) {
				parkTime[all[i].id] = 0;
			}
			parkTime[all[i].id] += inTime;
			if(parkTime[all[i].id] > maxTime) maxTime = parkTime[all[i].id];
		}
	}
	
	sort(valid,valid+index,cmpByTime);
	int now = 0,numCar = 0;
	for(int i = 0; i < k;i++){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int time = timeToInt(hh,mm,ss);
		while(now < index && valid[now].time <= time ){
			if(valid[now].in) numCar++;
			else numCar--; 
			now++;
		}
		printf("%d\n",numCar);
	}
	
	for(map<string,int>::iterator it = parkTime.begin();it != parkTime.end();it++){
		if(it->second == maxTime) printf("%s ",it->first.c_str());
	}
	
	printf("%02d:%02d:%02d\n",maxTime/3600,maxTime%3600/60,maxTime%60);
}

 
