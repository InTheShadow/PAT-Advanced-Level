#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 10010;
const int MAXK = 12;

struct Person{
	char name[10];
	int height;
}people[MAXN];

int cmp(Person a, Person b){
	if(a.height != b.height) return a.height > b.height;
	else return strcmp(a.name,b.name) < 0;
}

vector<int> row[MAXK];
vector<int> temp;

void sortForRow(int index){
	int len = row[index].size()-1;
	temp.resize(len+1);
	for(int i = 1; i <= len;i++){
		temp[i] = row[index][i];
	}
	int left = len/2,right = len/2+1,j = 1;
	while(left >= 1 || right <= len) {
		if(right <= len ) {
			row[index][right] = temp[j];
			j++;
			right++;
		}
		
		if(left >= 1){
			row[index][left] = temp[j];
			j++;
			left--;
		}
	}
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= n;i++){
		scanf("%s %d",&people[i].name,&people[i].height);
	}
	sort(people+1,people+1+n,cmp);
	int index = 1;
	
	for(int i = 1;i <= k;i++){
		int m;
		if(i == 1) m = n - n/k*(k-1); 
		else m = n/k;
		row[i].resize(m+1);
		for(int j = 1;j <= m;j++){
			row[i][j] = index;
			index++;
		}
		sortForRow(i);
	}
	
	for(int i = 1;i <= k;i++){
		for(int j = 1; j <= row[i].size()-1;j++){
			printf("%s",people[row[i][j]].name);
			if(j != row[i].size() - 1) printf(" ");
		}
		printf("\n");
	}
}

