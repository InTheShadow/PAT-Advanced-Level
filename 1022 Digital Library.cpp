#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<set>
using namespace std;
map<string,set<int>> title,author,key,pub,year;
void query(map<string,set<int>>& m,string& str){
	if(m.find(str) != m.end()){
		for(set<int>::iterator it = m[str].begin();it != m[str].end();it++){
			printf("%07d\n",*it);
		}
	}
	else {
		printf("Not Found\n");
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		int id;
		string ttitle,tauthor,tkey,tpub,tyear;
		scanf("%d",&id);
		getchar();
		getline(cin,ttitle);
		title[ttitle].insert(id);
		getline(cin,tauthor);
		author[tauthor].insert(id);
		while(cin >> tkey){
			key[tkey].insert(id);
			char c = getchar();
			if(c == '\n') break;
		} 
		getline(cin,tpub);
		pub[tpub].insert(id);
		getline(cin,tyear);
		year[tyear].insert(id);
	}
	int m;
	scanf("%d",&m);
	for(int i = 0;i < m;i++){
		int num;
		scanf("%d: ",&num);
		string temp;
		getline(cin,temp);
		cout << num << ": " << temp << endl;
		switch(num){
			case 1:query(title,temp);break;
			case 2:query(author,temp);break;
			case 3:query(key,temp);break;
			case 4:query(pub,temp);break;
			case 5:query(year,temp);break;
			default:break;
		}
	}
}
