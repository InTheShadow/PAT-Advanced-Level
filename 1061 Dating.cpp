#include<string>
#include<iostream>
#include<iomanip>
using namespace std;

string s1,s2,s3,s4;
string week[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
	cin >>  s1 >> s2 >> s3 >> s4;
	int i;
	for(i = 0; i < s1.length() && i < s2.length();i++){
		if(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
			cout << week[s1[i]-'A'] << " ";
			break;
		}		
	}
	i++;
	cout.width(2);
	cout.fill('0');
	cout.setf(ios::right);
	while(i < s1.length() && i < s2.length()){
		if(s1[i] == s2[i]){
			if(s1[i] >= 'A' && s1[i] <= 'N') {
				cout << int(s1[i] - 'A' + 10) << ':';
				break;
			}
			else if(s1[i] >= '0' && s1[i] <= '9') {
				cout << int(s1[i] - '0') << ':';
				break;
			}
		}
		i++;
	}
	
	cout.width(2);
	cout.fill('0');
	cout.setf(ios::right);
	for(int j = 0;j < s3.length() && j < s4.length();j++){
		if(s3[j] == s4[j]) {
			if((s3[j] >= 'A' && s3[j] <= 'Z') || (s3[j] >= 'a' && s4[j] <= 'z')){
				cout << j;
				break;
			}

		}
	}
	
	
	
}
