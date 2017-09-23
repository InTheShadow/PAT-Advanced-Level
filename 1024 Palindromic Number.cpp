#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;

void add(){
	string t = s;
	reverse(t.begin(),t.end());
	int length = t.length(),carry = 0;
	for(int i = 0;i<length;i++){
		s[i] = t[i] + s[i] - '0' + carry;
		carry = 0;
		if(s[i] > '9'){
			s[i] = s[i] - 10;
			carry = 1;
		}
	}
	if(carry == 1) s = s + '1';
	reverse(s.begin(),s.end());
}

int main(){
	int cnt;
	cin >> s >> cnt;
	for(int i = 0; i< cnt;i++){
		string t = s;
		reverse(t.begin(),t.end());
		if(s == t) {
			cout << s << endl;
			cout << i << endl;
			return 0;
		}
		add();
	}
	cout << s << endl;
	cout << cnt << endl;
}


