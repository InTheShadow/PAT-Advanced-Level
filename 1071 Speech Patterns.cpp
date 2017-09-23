#include<string>
#include<iostream>
#include<map>
using namespace std;

bool check(char c){
	return (c >= '0' && c <= '9')||
		(c >= 'A' && c <= 'Z')||
		(c >= 'a' && c <= 'z');
}

string str;
map<string,int> count;
int main(){
	//cin
	getline(cin,str);
	int i = 0;
	while(i < str.length()){
		string word;
		while(i < str.length() && check(str[i])){
			char c = str[i];
			if(c >= 'A' && c <= 'Z') c = c + 'a' - 'A';
			word += c;
			i++;
		}
		
		if(word != ""){
			if(count.find(word) != count.end() ) count[word]++;
			else count[word] = 1;
		}

		
		while(i < str.length() && check(str[i]) == false){
			i++;
		}
		
	}
	
	int max = 0;
	string ans;
	for(map<string,int>::iterator it = count.begin();it != count.end();it++){
		if(it->second > max) {
			max = it->second;
			ans = it->first;
		}
	}
	
	cout << ans << " " << max << endl;
}
