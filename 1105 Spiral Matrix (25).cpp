#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 10010;
const int maxc = 210;

int matrix[maxc][maxc];
int data[maxn];

void getMN(int mn, int& m,int &n){
	m = (int)ceil(sqrt(mn*1.0));
	while(mn%m != 0) m++;
	n = mn/m;
}

void setMatrix(int m,int n){
	int mn = m*n;
	int left = 0,right = n-1,up = 0, down = m-1,len = 0;
	int i = 0,j = 0;
	while(len < mn){
		while(len < mn) {
			matrix[i][j] = data[len++];
			if(j == right) break;
			j++;
		}
		up++;
		i++;
		
		
		while(len < mn){
			matrix[i][j] = data[len++];
			if(i == down) break;
			i++;
		}
		right--;
		j--;
		
		
		while(len < mn){
			matrix[i][j] = data[len++];
			if(j == left) break;
			j--;
		}
		down--;
		i--;
		
		while(len < mn){
			matrix[i][j] = data[len++];
			if(i == up) break;
			i--;
		}
		left++;
		j++;	
	}
}

void printMatrix(int m,int n){
	if(m == 1 && n == 1){
		printf("%d",data[0]);
		return;
	}
	for(int i = 0;i < m;i++){
		for(int j = 0; j < n;j++){
			if(j != 0)printf(" %d",matrix[i][j]);
			else printf("%d",matrix[i][j]);
		}
		printf("\n");
	}
}

int cmp(int a,int b){
	return a > b; 
}

int main(){
	int mn,n,m;
	scanf("%d",&mn);
	getMN(mn,m,n);
	for(int i = 0; i < mn;i++){
		scanf("%d",&data[i]);
	}
	sort(data,data+mn,cmp);
	setMatrix(m,n);
	printMatrix(m,n);
}

