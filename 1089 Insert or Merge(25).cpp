#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 110;

int origin[maxn],tempOri[maxn],changed[maxn];
int n;

bool isSame(int a[],int b[]){
	for(int i = 0; i< n;i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}

void printArray(int a[]){
	for(int i = 0 ;i < n;i++){
		printf("%d",a[i]);
		if(i < n-1) printf(" ");
	}
	printf("\n");
}

bool insertSort(){
	bool flag = false;
	for(int i = 1; i < n;i++){
		if(i != 1 && isSame(tempOri,changed)){
			flag = true;
		}
		
		int temp = tempOri[i], j = i;
		while(j > 0 && tempOri[j-1] > temp){
			tempOri[j] = tempOri[j-1];
			j--;
		}
		
		tempOri[j] = temp;
		if(flag) return true;
	}
	return false;
}

bool mergeSort(){
	bool flag = false;
	for(int step = 2; step/2 <= n;step *= 2){
		if(step != 2 && isSame(tempOri,changed)){
			flag = true;
		}
		for(int i = 0; i < n;i += step ){
			sort(tempOri+i,tempOri+min(i+step,n));
		}
		if(flag) return true;
	}
	return false;
}

int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&origin[i]);
		tempOri[i] = origin[i];
	}
	for(int i = 0; i < n;i++){
		scanf("%d",&changed[i]);
	}
	
	if(insertSort()){
		printf("Insertion Sort\n");
		printArray(tempOri);
		return 0;
	}
	
	for(int i = 0; i < n;i++){
		tempOri[i] = origin[i];
	}
	
	if(mergeSort()){
		printf("Merge Sort\n");
		printArray(tempOri);
	}
	return 0;
}
