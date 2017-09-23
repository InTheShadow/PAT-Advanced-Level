#include<cstring>
#include<cstdio>
using namespace std;
char str1[1010],str2[1010];
int count[256] = {0};

int main(){
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	char c;
	for(int i = 0; i < len1;i++){
		c = str1[i];
		count[c]++;
	}
	
	int misa = 0;
	for(int i = 0;i < len2;i++){
		c = str2[i];
		count[c]--;
		if(count[c] < 0) misa++;
	}
	
	if(misa > 0) printf("No %d\n",misa);
	else printf("Yes %d\n",len1 - len2);
	
}
