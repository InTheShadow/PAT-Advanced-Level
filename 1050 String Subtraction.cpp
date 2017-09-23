#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

char s1[10001],s2[10001];
bool flag[256] = {false};

int main(){
	cin.getline(s1,10001);
	cin.getline(s2,10001);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for(int i = 0; i < len2;i++){
		flag[s2[i]] = true;
	}
	for(int i = 0;i < len1;i++){
		if(!flag[s1[i]]) printf("%c",s1[i]);
	}
}
