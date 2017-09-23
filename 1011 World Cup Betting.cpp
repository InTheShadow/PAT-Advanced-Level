#include<iostream>
#include<iomanip>
using namespace std;


int main(){
	char result[3];
	float a,b,c,profit[3];
	for(int i = 0;i<3;i++){
		cin >> a >> b >> c;
		float max = a;
		//compute max profit for one game 
		if(b > max) max = b;
		if(c > max) max = c;
		profit[i] = max;	
	
		//get bet result
		if(max == a) result[i] = 'W';
		else if(max == b) result[i] = 'T';
		else result[i] = 'L';
	}
	
	//print bet result 
	for(int i = 0;i < 3;i++) cout << result[i] << " ";
	
	//print total profit
	float total = (profit[0]*profit[1]*profit[2]*0.65f-1.0f)*2;
	 cout << fixed << setprecision(2) << total << endl;
	
}
