#include<iostream>
#include<string>
#include<map>
using namespace std;
const int MAXM = 1010;

map<string,int> awarded; 
string fl[MAXM];

int main(){
	int m,n,s;
	cin >> m >> n >> s;
	for(int i = 1;i <= m;i++){
		cin >> fl[i];
	}
	
	int i = s;
	if(i > m) cout << "Keep going..." << endl;
	while(i <= m){
		string temp = fl[i];
		if(awarded.find(temp) == awarded.end()) {
			awarded[temp] = 1;
			cout << temp << endl;
			i += n;
		}
		else {
			i++;
		}
	}
}
