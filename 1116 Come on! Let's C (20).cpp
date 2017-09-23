#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 10010;

int first;
bool isPrime[MAXN] = {true};
bool Minion[MAXN] = {false};
bool checked[MAXN] = {false};
bool attended[MAXN] = {false};

void getPrime(int n){
	isPrime[1] = false;
	for(int i = 2;i <= n;i++){
		if(isPrime[i] == true){
			for(int j = i+i; j <=n ;j +=i){
				isPrime[j] = false;
			}
		}
	} 
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		isPrime[i] = true;
	}
	getPrime(n);
	scanf("%d",&first);
	attended[first] = true;
	for(int i = 2;i <= n;i++){
		int id;
		scanf("%d",&id);
		if(isPrime[i]) {
			Minion[id] = true;
		}
		attended[id] = true;
	}
	
	int k;
	scanf("%d",&k);
	for(int i = 1;i <= k;i++){
		int id;
		scanf("%d",&id);
		printf("%04d: ",id);
		if(checked[id]) printf("Checked\n");
		else if(first == id) printf("Mystery Award\n");
		else if(Minion[id]) printf("Minion\n");
		else if(attended[id]) printf("Chocolate\n");
		else printf("Are you kidding?\n");
		if(attended[id])checked[id] = true;
	}
}
