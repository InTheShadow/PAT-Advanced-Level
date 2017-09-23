#include<cstdio>
#include<cstring>

struct card{
	char a;
	int b;
};
card deck[55];
card temp[55];
int shuffle[55];

int main(){
	for(int i = 1; i <= 13;i++) {
		deck[i].a = 'S';
		deck[i].b = i;
	}
	for(int i = 14; i <= 26;i++) {
		deck[i].a = 'H';
		deck[i].b = i-13;
	}
	for(int i = 27; i <= 39;i++) {
		deck[i].a = 'C';
		deck[i].b = i-26;
	}
	
	for(int i = 40; i <= 52;i++) {
		deck[i].a = 'D';
		deck[i].b = i-39;
	}
	for(int i = 53;i<=54;i++){
		deck[i].a = 'J';
		deck[i].b = i-52;
	}
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=54;i++){
		scanf("%d",&shuffle[i]);
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1; j <= 54;j++){
			temp[j] = deck[j];
		}
		for(int j = 1; j <= 54;j++){
			deck[shuffle[j]] = temp[j];
		}
	}
	
	for(int i = 1;i<=54;i++){
		if(i==54) printf("%c%d",deck[i].a,deck[i].b);
		else printf("%c%d ",deck[i].a,deck[i].b);
	}
}
