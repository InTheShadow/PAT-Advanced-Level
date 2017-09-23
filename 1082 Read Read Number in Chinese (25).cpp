#include<iostream>
#include<string>
#include<vector>
using namespace std;

string number[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string smallUnit[4] = {"","Shi","Bai","Qian"};
string ling = "ling";
string bigUnit[4] = {"","Wan","Yi"};
string fu = "Fu";

string a;
vector<string> res;
vector<int> mark;

inline void pushBack(string temp){
	if(temp != "") res.push_back(temp);
}

void solveNoneZeros(int start,int end,int& markI){
	int index = mark[markI] - start;
	for(int i = start;i <= end;i++){
		pushBack(number[a[i]-'0']);
		pushBack(smallUnit[index]);
		index--;
	}
	if(end == mark[markI]) {
		pushBack(bigUnit[markI]); 
	}
} 

void setMark(int len){
	mark.push_back(len-1);
	for(int i = len-2;i >= 0;i--){
		if((len - 1 - i) % 4 == 0) mark.push_back(i);
	}
	mark.push_back(-1);
};

void solveZeros(int start,int end,int& markI){
	if(start - 1 >  mark[markI+1] && end >= mark[markI]) pushBack(bigUnit[markI]);
	if(end != a.length() - 1 && end != mark[markI]) pushBack(ling);
	while( end < a.length() && end >= mark[markI]) markI--;

}

inline bool isZero(int n){return a[n] - '0' == 0; } 

int main(){
	cin >> a;
	if(a[0] == '-') {
		res.push_back(fu);
		a.erase(a.begin());
	}
	
	if(a[0] == '0') {
		cout << ling;
		return 0;
	}
	
	int len = a.length();
	setMark(len);
	int markI = mark.size()-2;
	int start = 0,end = 0;
	while(start < a.length()){
		if(isZero(start)){
			while(end < a.length() && isZero(end)) end++;
			end--;
			solveZeros(start,end,markI);
			
		}
		else{
			while(end <= mark[markI] && isZero(end) == false) end++;
			end--;
			solveNoneZeros(start,end,markI);
			if(end == mark[markI]) markI--;
		} 
		
		end = end+1;
		start = end;
	}
	
	for(int i = 0;i<res.size();i++){
		if(i == 0) cout << res[i];
		else cout << " " << res[i];
	}
	return 0;
}
