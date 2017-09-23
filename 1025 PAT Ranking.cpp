#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
struct student{
	LL no;
	int score,locRank,loc,finRank; 
};
bool cmp(student a,student b){
	if(a.score != b.score){
		return a.score > b.score;
	}
	else {
		return a.no < b.no;
	}
}

int main(){
	int n,m;
	scanf("%d",&n);
	vector<student> final;
	for(int i = 1;i <= n;i++){
		scanf("%d",&m);
		vector<student> temp;
		for(int j = 1;j<=m;j++){
			student t;
			scanf("%lld",&t.no);
			scanf("%d",&t.score);
			t.loc = i;
			temp.push_back(t);
		}
		sort(temp.begin(),temp.end(),cmp);
		temp[0].locRank = 1;
		final.push_back(temp[0]);
		for(int i = 1;i<temp.size();i++){
			if(temp[i].score == temp[i-1].score) temp[i].locRank = temp[i-1].locRank;
			else temp[i].locRank = i+1;
			final.push_back(temp[i]);
		}
	}
	sort(final.begin(),final.end(),cmp);
	final[0].finRank = 1;
	for(int i = 1;i<final.size();i++){
		if(final[i].score == final[i-1].score) final[i].finRank = final[i-1].finRank;
		else final[i].finRank = i + 1; 
	}
	printf("%d\n",final.size());
	for(int i = 0; i< final.size();i++){
		printf("%013lld %d %d %d\n",final[i].no,final[i].finRank,final[i].loc,final[i].locRank);
	}
}

