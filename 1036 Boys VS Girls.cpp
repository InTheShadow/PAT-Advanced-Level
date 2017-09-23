#include<iostream>
#include<vector>
using namespace std;

struct node{
	string name;
	char sex;
	string id;
	int grade;
};

vector<node> v;
int n,diff,mMinInd,fMaxInd;

int main(){
	//scanf
	scanf("%d",&n);
	v.resize(n);
	for(int i = 0; i< n;i++){
		cin >> v[i].name;
		getchar();
		v[i].sex = getchar();
		cin >> v[i].id>> v[i].grade;
	}
	
	//execute
	mMinInd = -1;
	fMaxInd = -1;
	int min = 101,max = -1;
	for(int i = 0;i<n;i++){
		if(v[i].sex == 'M'){
			if(v[i].grade < min){
				min = v[i].grade;
				mMinInd = i;
			}
		}
		else {
			if(v[i].grade > max){
				max = v[i].grade;
				fMaxInd = i;
			} 
		}
	}
	
	diff = 101;
	if(mMinInd != -1 && fMaxInd != -1) diff = v[fMaxInd].grade - v[mMinInd].grade;
	
	//printf
	if(fMaxInd == -1) printf("Absent\n");
	else cout << v[fMaxInd].name <<  " " << v[fMaxInd].id  << endl;
	
	if(mMinInd == -1) printf("Absent\n");
	else cout << v[mMinInd].name  << " " << v[mMinInd].id  << endl;
	
	if(diff == 101) printf("NA\n");
	else printf("%d\n",diff);
}
