#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 1010;

struct Node{
	int order;
	char c;
}dOrder[255];

bool isBroken[255] = {false};
string a;

bool cmp(Node a,Node b){
	return a.order < b.order;
}

int main(){
	int k;
	scanf("%d",&k);
	cin >> a;
	int i = 0,index = 1;
	char temp;
	for(int i = 0; i < 255;i++){
		dOrder[i].order = MAXN;
		dOrder[i].c = (char)i;
	}
	while(i < a.length()){
		temp = a[i];
		int num = 0;
		while(i < a.length() && a[i] == temp && num < k){
			i++;
			num++;
		}
		if(num == k && dOrder[temp].order == MAXN) {
			dOrder[temp].order = index++;
			isBroken[temp] = true;
		}
		else if(num != k && dOrder[temp].order != MAXN){
			dOrder[temp].order = MAXN;
			isBroken[temp] = false;
		}
	} 
	
	sort(dOrder,dOrder+255,cmp);
	
	int j = 0;
	while(dOrder[j].order != MAXN){
		printf("%c",dOrder[j].c);
		j++;
	}
	printf("\n");
	
	for(int i = 0;i < a.length();i++){
		printf("%c",a[i]);
		if(isBroken[a[i]]){
			i += k-1;
		}
	}
	printf("\n");
} 
