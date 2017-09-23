#include<iostream>
#include<string>
using namespace std;

int n; 
string deal(string s,int &e){
	int k = 0;
	e = 0;
	while(s.length() > 0 && s[0] == '0') s.erase(s.begin());
	if(s[0] == '.'){
		s.erase(s.begin());
		while(s.length() > 0 && s[0] == '0') {
			s.erase(s.begin());
			e--; 
		}
	}
	
	else{
		while(k < s.length() && s[k] != '.') {
			k++;
			e++;
		}
		if(k < s.length()) s.erase(s.begin() + k);
	}
	
	if(s.length() == 0 ) e = 0;
	
	k = 0;
	int num = 0;
	string res;
	while(num < n){
		if( k < s.length() ) res += s[k++];
		else res += '0';
		num++;
	}
	return res;
}


int main(){
	string a,b,ca,cb;
	cin >> n >> a >> b;
	int ea,eb;
	ca = deal(a,ea);
	cb = deal(b,eb);
	
	if(ca == cb && ea == eb){
		cout << "YES 0." << ca << "*10^" << ea << endl; 
	}
	else {
		cout << "NO 0." << ca << "*10^" << ea << " 0." << cb << "*10^" << eb << endl;
	}
}
