#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 40010;
const int maxs = 101;

struct Student{
	int ge,gi;
	int total,id;
	vector<int> choice;
}stu[maxn]; 

struct School{
	int quota;
	int stuNum;
	vector<int> stuId;
	int lastInd;
}sch[maxs];

int cmpStu(Student a,Student b){
	if(a.total != b.total) return a.total > b.total;
	else return a.ge > b.ge;
}

int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 0;i < m;i++){
		scanf("%d",&sch[i].quota);
		sch[i].stuNum = 0;
		sch[i].lastInd = -1;
	}
	
	for(int i = 0;i < n;i++){
		scanf("%d%d",&stu[i].ge,&stu[i].gi);
		stu[i].choice.resize(k);
		stu[i].total = stu[i].ge + stu[i].gi;
		for(int j = 0;j < k;j++){
			scanf("%d",&stu[i].choice[j]);
		} 
		stu[i].id = i;
	}
	
	sort(stu,stu+n,cmpStu);
	for(int i = 0; i < n;i++){
		for(int j = 0; j < k;j++){
			int s_id = stu[i].choice[j];
			int last_ind = sch[s_id].lastInd;
			if(sch[s_id].stuNum < sch[s_id].quota){
				sch[s_id].stuNum++;
				sch[s_id].stuId.push_back(stu[i].id);
				sch[s_id].lastInd = i;
				break;
			}
			
			else if(last_ind >= 0 && sch[s_id].stuNum >= sch[s_id].quota
				&& stu[i].total == stu[last_ind].total
				&& stu[i].ge == stu[last_ind].ge){
					sch[s_id].stuNum++;
					sch[s_id].stuId.push_back(stu[i].id);
					break;
				}
		}
	}
	
	for(int i = 0; i < m;i++){
		if(sch[i].stuNum == 0){
			printf("\n");
		}
		else {
			sort(sch[i].stuId.begin(),sch[i].stuId.end());
			for(int j = 0; j < sch[i].stuId.size();j++){
				if(j == 0) printf("%d",sch[i].stuId[j]);
				else printf(" %d",sch[i].stuId[j]);
				if(j == sch[i].stuId.size() - 1) printf("\n");
			}
		}
	}
}
