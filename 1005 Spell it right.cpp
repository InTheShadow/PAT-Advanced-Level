#include<iostream>
#include<vector>
using namespace std;
int main(){
	string s[10]  = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	string a;
	cin >> a;
	int sum = 0;
	for(int i = 0;i<a.length();i++){
		sum+=a[i]-'0';
	}	
	vector<int> v;
	while(sum != 0){
		v.push_back(sum%10);
		sum = sum/10;
	}
	
	int len = v.size();
	if(len == 0) cout << s[0];
	else cout << s[v[len-1]];
	for(int i =len-2;i>=0;i--) cout << " " << s[v[i]];
	return 0;
}
