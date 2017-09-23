#include<string>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<iomanip> 
using namespace std;

bool judge(string s,double& d){
	d = 0;
	bool minus = false;
	if(s[0] == '-') {
		minus = true;
		s.erase(s.begin());
	}
	if(s.length() == 0) return false;
	int i = 0;
	while(s[i] != '.' && i < s.length()){
		if(s[i] <= '9' && s[i] >= 0) d = d*10.0+s[i]-'0';
		else return false;
		i++;
	}
	if(i == s.length()) { 
		if(minus) d = -d;
		if(d > 1000.0 || d < -1000.0) return false;
		else return true;
	}
	
	i++;
	double little = 0;
	int num = 0;
	while(i < s.length()){
		if(s[i] <= '9' && s[i] >= '0' ) {
			num++;
			little = little*10.0+s[i]-'0';
			if(num >= 3) return false; 
		}
		else return false;
		i++;
	}
	d = d + little/pow(10,num);
	if(minus) d = -d;
	if(d > 1000.0 || d < -1000.0) return false;
	return true;
}

int main(){
	int n;
	scanf("%d",&n);
	string temp;
	double data,sum = 0.0;
	int num = 0;
	for(int i = 0;i < n;i++){
		cin >> temp;
		if(judge(temp,data)){
			sum += data;
			num++;
		}
		else cout << "ERROR: " << temp << " is not a legal number" << endl;
	}
	cout.setf(ios::fixed);
	if(num == 0) cout << "The average of 0 numbers is Undefined" << endl;
	else if(num == 1) cout << "The average of 1 number is " << setprecision(2)<< sum <<endl;
	else cout << "The average of " << num <<" numbers is " << setprecision(2)<< sum/num <<endl;
}
