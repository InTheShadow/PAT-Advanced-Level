#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100010;
const int MAXNUM = 10010;

struct node{
	int address;
	int value;
	int next;
} nodes[MAXN],result[MAXN],removed[MAXN];

bool exist[MAXNUM] = {false};

int removedLen = 0,resLen = 0;
int sortLink(int head){
	for(int p = head; p != -1; p = nodes[p].next){
		if(exist[abs(nodes[p].value)]) {
			removed[removedLen++] = nodes[p];
		}
		else {
			exist[abs(nodes[p].value)] = true;
			result[resLen++] = nodes[p];
		}
	} 
}

void outputLink(){
	for(int i = 0;i < resLen;i++){
		if(i == resLen-1) printf("%05d %d -1\n",result[i].address,result[i].value);
		else printf("%05d %d %05d\n",result[i].address,result[i].value,result[i+1].address); 
	}
	
	for(int i = 0;i < removedLen;i++){
		if(i == removedLen-1) printf("%05d %d -1\n",removed[i].address,removed[i].value);
		else printf("%05d %d %05d\n",removed[i].address,removed[i].value,removed[i+1].address); 
	}
}

int main(){
	int head,n,add;
	scanf("%d %d",&head,&n);
	for(int i = 0; i < n;i++){
		scanf("%d",&add);
		scanf("%d%d",&nodes[add].value,&nodes[add].next);
		nodes[add].address = add;
	}
	sortLink(head);
	outputLink();
}



