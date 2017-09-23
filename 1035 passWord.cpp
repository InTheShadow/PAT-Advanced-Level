#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct node{
	string str;
	string id;
	bool modified;
};
vector<node> v;

int n,m;

int main(){
	//scanf
	scanf("%d",&n);
	v.resize(n);
	for(int i = 0;i<n;i++){
		cin >> v[i].id >> v[i].str;
		v[i].modified = false;
	}
	
	//execute
	m = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j< v[i].str.length();j++){
			switch(v[i].str.at(j)){
				case '1':v[i].str[j] = '@';v[i].modified = true;break;
				case '0':v[i].str[j] = '%';v[i].modified = true;break;
				case 'l':v[i].str[j] = 'L';v[i].modified = true;break;
				case 'O':v[i].str[j] = 'o';v[i].modified = true;break;
				default:break;
			}
		}
		if(v[i].modified) m++;
	}
	
	//printf
	if(m==0){
		if(n>1) printf("There are %d accounts and no account is modified",n);
		else printf("There is 1 account and no account is modified");
	}
	else {
		printf("%d\n",m);
		for(int i = 0;i < n;i++){
			if(v[i].modified) cout << v[i].id << " " << v[i].str << endl;
		}
	}
}
