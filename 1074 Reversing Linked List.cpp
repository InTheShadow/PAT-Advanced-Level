#include<cstdio>
#include<algorithm>
using namespace std;

const int maxa = 100010;

struct node{
	int value;
	int next; 
	int address;
} nodes[maxa];


node temp[maxa];
int len = 0;
void reverseLink(int head,int k){
	len = 0;
	for(int p = head; p != -1;p = nodes[p].next){
		temp[len++] = nodes[p];
		if(len%k == 0) {
			reverse(temp+len-k,temp+len);
		}
	}
}

void outputLink(){
	for(int i = 0; i < len;i++){
		if(i == len-1) printf("%05d %d -1\n",temp[i].address,temp[i].value);
		else printf("%05d %d %05d\n",temp[i].address,temp[i].value,temp[i+1].address); 
	}
}

int main(){
	int head,n,k,add;
	scanf("%d %d %d",&head,&n,&k);
	for(int i = 0; i < n;i++){
		scanf("%d",&add);
		scanf("%d%d",&nodes[add].value,&nodes[add].next);
		nodes[add].address = add;
	}
	reverseLink(head,k);
	outputLink();
}
