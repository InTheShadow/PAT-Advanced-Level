//Zero on Earth is called "tret" on Mars.
//The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
//For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;

string oneToStr[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", 
	"aug", "sep", "oct", "nov", "dec"};

string tenToStr[13] = {"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei",
	 "elo", "syy", "lok", "mer", "jou"};
	 
string numToStr[171];
map<string,int> strToNum;

int main(){
	for(int i = 0; i < 13;i++){
		numToStr[i] = oneToStr[i];
		strToNum[oneToStr[i]] = i;
		numToStr[i*13] = tenToStr[i];
		strToNum[tenToStr[i]] = i*13;
	}
	
	for(int i = 1; i < 13;i++){
		for(int j = 1;j < 13;j++){
			numToStr[i*13+j] = tenToStr[i] + " " + oneToStr[j];
			strToNum[numToStr[i*13+j]] = i*13+j; 
		}
	}
	
	int n;
	scanf("%d%*c",&n);
	while(n--){
		string str;
		getline(cin,str);
		if(str[0] >= '0' && str[0] <= '9'){
			int num = 0;
			for(int i = 0; i < str.length();i++){
				num = num*10+ (str[i] - '0');
			}
			cout << numToStr[num] << endl;
		}
		else {
			cout << strToNum[str] << endl;
		}
	}
}
