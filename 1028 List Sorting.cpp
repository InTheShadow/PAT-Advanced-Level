#include<cstdio>
#include<cstring> 
#include<algorithm>
using namespace std;

struct Student{
	int id;
	char name[10];
	int grade;
}student[100010];

bool cmpId(Student a, Student b){
	return a.id < b.id;
}

bool cmpName(Student a,Student b){
	if(strcmp(a.name,b.name) == 0){
		return a.id < b.id;
	}
	else {
		return strcmp(a.name,b.name) < 0;
	}
}

bool cmpGrade(Student a,Student b){
	if(a.grade == b.grade){
		return a.id < b.id;
	}
	else {
		return a.grade < b.grade;
	}	
}

int main(){
	int n,c;
	scanf("%d %d",&n,&c);
	for(int i = 0;i < n;i++){
		scanf("%d %s %d",&student[i].id,&student[i].name,&student[i].grade);
	} 
	switch(c){
		case 1:sort(student,student+n,cmpId);break;
		case 2:sort(student,student+n,cmpName);break;
		case 3:sort(student,student+n,cmpGrade);break;
		default:break;
	}
	for(int i = 0;i < n;i++){
		printf("%06d %s %d\n",student[i].id,student[i].name,student[i].grade);
	}
} 
