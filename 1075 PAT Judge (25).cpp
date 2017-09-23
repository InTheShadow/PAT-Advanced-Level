#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 10010;
struct Student{
	int id;
	int s[6];
	int solves;
	int score;
	bool flag;
}stu[maxn];

bool cmp(Student a,Student b){
	if(a.score != b.score) return a.score > b.score;
	else if(a.solves != b.solves) return a.solves > b.solves;
	else return a.id < b.id;
}

int n,m,k;
int p[6];
void init(){
	for(int i = 1;i<=n;i++){
		stu[i].id = i;
		stu[i].score = 0;
		stu[i].solves = 0;
		stu[i].flag = false;
		memset(stu[i].s,-1,sizeof(stu[i].s));
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= m;i++){
		scanf("%d",&p[i]);
	}
	init();
	for(int i = 1;i <= k;i++){
		int id,p_id,s;
		scanf("%d%d%d",&id,&p_id,&s);
		if(s != -1) stu[id].flag = true;
		
		if(s == -1 && stu[id].s[p_id] == -1) {
			stu[id].s[p_id] = 0;
		}
		
		if(stu[id].s[p_id] < p[p_id] && s == p[p_id]) stu[id].solves++;
		
		if(stu[id].s[p_id] < s) stu[id].s[p_id] = s;		
	}
	
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(stu[i].s[j] != -1) stu[i].score += stu[i].s[j];
		}
	}
	
	sort(stu+1,stu+n+1,cmp);
	int r = 1;
	for(int i = 1;i <= n && stu[i].flag == true;i++){
		if(i > 1 && stu[i].score != stu[i-1].score) r = i;
		printf("%d %05d %d",r,stu[i].id,stu[i].score);
		for(int j = 1; j <=m;j++){
			if(stu[i].s[j] == -1) printf(" -");
			else printf(" %d",stu[i].s[j]);
		} 
		printf("\n");
	}
}
