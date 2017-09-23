#include<cstdio>
#include<queue>
using namespace std;

const int MAXNP = 1010;

struct mouse{
	int weight;
	int rank;
}mouses[MAXNP];
queue<int> q;
int order[MAXNP];
int np,ng,rounds;

void rankMouses(){
	rounds = 1;
	for(int i = 0; i < np;i++){
		q.push(order[i]);
	}
	int roundMax = np,roundI = 0,maxI = -1,groups;
	if(np % ng == 0) groups = np/ng;
	else groups = np/ ng+1;
	while(q.size() > 0 ){
		int ind = q.front();
		q.pop();
		if(maxI == -1) maxI = ind;
		else if(mouses[ind].weight > mouses[maxI].weight) maxI = ind;
		mouses[ind].rank = groups+1;
		roundI++;
		if(roundI % ng == 0 || roundI == roundMax){
			q.push(maxI);
			if(roundI == roundMax) {
				roundMax = q.size();
				if(q.size() == 1) break;
				if(q.size() % ng == 0)groups = q.size()/ng;
				else groups = q.size()/ng+1;
				roundI = 0;
			}
			maxI = -1;
		} 
	}
	mouses[maxI].rank = 1;
}

void printRes(){
	for(int i = 0; i < np;i++){
		if(i == 0) printf("%d",mouses[i].rank);
		else printf(" %d",mouses[i].rank);
	}
}

int main(){
	scanf("%d%d",&np,&ng);
	for(int i = 0; i < np;i++ ){
		scanf("%d",&mouses[i].weight);
	}
	for(int i = 0; i < np;i++){
		scanf("%d",&order[i]);
	}
	rankMouses();
	printRes();
}

