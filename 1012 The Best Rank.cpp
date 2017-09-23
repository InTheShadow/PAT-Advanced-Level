#include<algorithm>
#include<cstdio>
using namespace std;
struct Student{
	int id,best;
	int score[4],rank[4];
} ;

struct Result{
	int best_rank;
	char course;
	bool exist;
};
int flag; 
bool cmp(Student a,Student b){return a.score[flag] > b.score[flag]; }

int main(){
	//scanf
	int n,m;
	scanf("%d%d",&n,&m);
	Student* stu = new Student[n];
	Result* res = new Result[m];
	for(int i = 0;i<n;i++){
		scanf("%d%d%d%d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
		stu[i].score[0] = (stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3.0+0.5;
	}
	//get rank for evenry score
	for(flag = 0;flag<4;flag++){
		sort(stu,stu+n,cmp);
		for(int i = 0;i<n;i++){
			stu[i].rank[flag] = i+1;
			if( i > 0 && stu[i].score[flag] == stu[i-1].score[flag]){
				stu[i].rank[flag] = stu[i-1].rank[flag];
			}
		}

	}
	//get best rank index
	for(int i = 0;i<n;i++){
		int min = stu[i].rank[0];
		for (int j = 1; j < 4;j++){
			if(stu[i].rank[j] < min ) min = stu[i].rank[j];
		}

		for(int j = 0;j<4;j++){
			if(stu[i].rank[j] == min) {
				stu[i].best = j;
				break;
			}
		}
	}
	//scanf for check rank and get Result
	char map[4] = {'A','C','M','E'};
	for(int i = 0;i < m ;i++){
		int id;
		scanf("%d",&id);
		res[i].exist = false;
		for(int j = 0;j < n;j++ ){
			if( stu[j].id == id){
				res[i].best_rank = stu[j].rank[stu[j].best];
				res[i].course = map[stu[j].best];
				res[i].exist = true;
				break;
			}
		}
	}
	//printf
	for(int i = 0; i < m;i++){
		if(res[i].exist)
			printf("%d %c\n",res[i].best_rank,res[i].course);
		else printf("N/A\n");
	}
	delete stu;
	delete res;
	
}
