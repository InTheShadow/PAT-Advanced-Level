#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;

const LL P = 10000019;
const LL MOD = 1000000007;
const int MAXN = 1010;

LL PowP[MAXN],H1[MAXN],H2[MAXN];
vector<pair<LL,LL> > pr1,pr2;

void init(){
	PowP[0] = 1;
	for(int i = 1;i < MAXN;i++){
		PowP[i] = (Pow[i-1]*P)%MOD;
	}
}

void callH(LL H[],string& str){
	H[0] = str[0];
	for(int i = 1; i < str.length();i++){
		H[i] = (H[i-1] * P+str[i])%MOD;
	}
}

LL callSingleSubH(LL H[],int i,int j){
	if(i == 0) return H[j];
	else return ((H[j] - H[i-1]*PowP[j-i+1]);
}





