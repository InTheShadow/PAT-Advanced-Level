#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Station{
	double priPD;
	double dis;
}; 

vector<Station> sta;

int cmp(Station a,Station b){
	return a.dis < b.dis;
}

int findBestSta(int now, int maxDis){
	int index = now;
	for(int i = now + 1; i < sta.size() && sta[i].dis - sta[now].dis <= maxDis;i++){
		if(sta[i].priPD <= sta[now].priPD) {
			index = i;
			break;
		}
		if(index == now) index = i;
		else if(sta[i].priPD < sta[index].priPD) index = i;
	}
	
	return index;
}

int main(){
	double cmax,d,davg,fullDis;
	int n;
	scanf("%lf%lf%lf%d",&cmax,&d,&davg,&n);
	fullDis = cmax*davg;
	sta.resize(n+1);
	
	double priPC;
	for(int i = 0; i < n;i++){
		scanf("%lf %lf",&priPC,&sta[i].dis);
		sta[i].priPD = priPC/davg;
	}
	sta[n].dis = d;
	sta[n].priPD = 0.0;
	
	sort(sta.begin(),sta.end(),cmp);
	int now = 0;
	double totalPri = 0.0;
	double totalDis = 0.0;
	double hasDis = 0.0;
	if(sta[0].dis != 0 ){
		printf("The maximum travel distance = 0.00\n");
	}
	else {
		while(now < n){
			double leftDis = d - sta[now].dis;
			double maxDis = min(fullDis,leftDis);
			int bestSta = findBestSta(now,maxDis);
			double nowLeftDis = sta[bestSta].dis-sta[now].dis;

			if(bestSta == now){
				totalDis = sta[now].dis+maxDis;
				break;	
			}
			else if(sta[bestSta].priPD <= sta[now].priPD){
				if(hasDis > nowLeftDis) hasDis -= nowLeftDis;
				else{
					totalPri += (nowLeftDis - hasDis)*sta[now].priPD;
					hasDis = 0.0;
				} 
				now = bestSta;
			}
			
			else {
				totalPri += (maxDis - hasDis)*sta[now].priPD;
				hasDis = maxDis - nowLeftDis;
				now = bestSta;
			}
		} 
	}
	
	if(totalDis != 0.0){
		printf("The maximum travel distance = %.2f\n",totalDis);
	}
	else {
		printf("%.2f\n",totalPri);
	}
}
