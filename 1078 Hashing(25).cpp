#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 10010;

bool isPrime(int n){
	if(n <= 1) return false;
	int sqr = (int)sqrt(n*1.0);
	for(int i= 2;i <= sqr;i++){
		if(n % i == 0) return false;
	}
	return true; 
}

bool hashTable[maxn] = {false};

int main(){
	int n,TSize,key;
	scanf("%d %d",&TSize,&n);
	while(isPrime(TSize) == false) TSize++;
	for(int i = 0; i < n;i++){
		scanf("%d",&key);
		int H = key % TSize;
		if(hashTable[H] == false){
			hashTable[H] = true;
			if(i == 0) printf("%d",H);
			else printf(" %d",H);
		}
		else {
			int step = 1;
			while(step < TSize){
				H = (key + step*step) % TSize;
				if(hashTable[H] == false){
					hashTable[H] = true;
					if(i == 0) printf("%d",H);
					else printf(" %d",H);
					break;
				}
				step++;
			}
			if(step >= TSize) {
				if(i == 0) printf("-");
				else printf(" -");
			}
		}
	}
	return 0;
}


