#include<cstdio>
using namespace std;
int arr[40];

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int index = 0;
	while(a != 0){
		arr[index++] = a%b;
		a /= b;
	}
	bool flag = true;
	for(int i = 0; i < index/2;i++){
		if(arr[i] != arr[index-i-1] ) {
			flag = false;
			break;
		}
	}
	
	if(flag) printf("Yes\n");
	else printf("No\n");
	
	for(int i = index-1;i>=0;i--){
		if(i == 0) printf("%d",arr[i]);
		else printf("%d ",arr[i]);
	}
	if(index == 0) printf("0");
} 
