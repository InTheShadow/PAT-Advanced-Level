#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 110;

int origin[maxn],tempOri[maxn],changed[maxn];
int n;

bool isSame(int a[],int b[]){
	for(int i = 1; i<= n;i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}

void printArray(int a[]){
	for(int i = 1 ;i <= n;i++){
		printf("%d",a[i]);
		if(i < n) printf(" ");
	}
	printf("\n");
}

bool insertSort(){
	bool flag = false;
	for(int i = 2; i <= n;i++){
		if(i != 2 && isSame(tempOri,changed)){
			flag = true;
		}
		
		int temp = tempOri[i], j = i;
		while(j > 1 && tempOri[j-1] > temp){
			tempOri[j] = tempOri[j-1];
			j--;
		}
		
		tempOri[j] = temp;
		if(flag) return true;
	}
	return false;
}

void downAdjust(int low,int high){
	int i = low,j = i*2;
	while(j <= high){
		if(j+1 <= high && tempOri[j+1] > tempOri[j]){
			j = j+1;
		}
		if(tempOri[i] <tempOri[j]){
			swap(tempOri[i],tempOri[j]);
			i = j;
			j = i*2;
		}
		else break;
	}
}

void createHeap(){
	for(int i = n/2;i>=1;i--){
		downAdjust(i,n);
	}
}

bool heapSort(){
	createHeap();
	bool flag = false;
	for(int i = n; i > 1;i--){
		if(i != n && isSame(tempOri,changed)){
			flag = true;
		}
		swap(tempOri[i],tempOri[1]);
		downAdjust(1,i-1); 
		if(flag) return true;
	}
	return false;
}

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&origin[i]);
		tempOri[i] = origin[i];
	}
	for(int i = 1; i <= n;i++){
		scanf("%d",&changed[i]);
	}
	
	if(insertSort()){
		printf("Insertion Sort\n");
		printArray(tempOri);
		return 0;
	}
	
	for(int i = 1; i <= n;i++){
		tempOri[i] = origin[i];
	}
	
	if(heapSort()){
		printf("Heap Sort\n");
		printArray(tempOri);
		return 0;
	}
	
	return 0;
}
