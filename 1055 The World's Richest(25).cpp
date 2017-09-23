#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
using namespace std;

struct Person{
	int age,worth;
	char name[10];
} p[maxn],valid[maxn];

bool cmp(Person a,Person b){
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else return strcmp(a.name,b.name) < 0;
}

int age[201] = {0};

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i = 0;i<N;i++){
		scanf("%s%d%d",p[i].name,&p[i].age,&p[i].worth);
	}
	
	sort(p,p+N,cmp);
	int index = 0;
	for(int i = 0;i < N;i++){
		if(age[p[i].age] < 100){
			age[p[i].age]++;
			valid[index] = p[i];
			index++;
		}
	}
	
	for(int i = 1;i <= K;i++){
		int M,aMin,aMax;
		scanf("%d%d%d",&M,&aMin,&aMax);
		printf("Case #%d:\n",i);
		int printNum = 0;
		for(int j = 0; j < index;j++){
			if(valid[j].age >= aMin && valid[j].age <= aMax){
				printf("%s %d %d\n",valid[j].name,valid[j].age,valid[j].worth);
				printNum++;
			}
			if(printNum == M) break;
		}
		if(printNum == 0) printf("None\n");
	}
}
