#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 10010;

int a[MAXN],n;



int getMaxLength(){
	priority_queue<double,vector<double>,greater<double> > q;
	for(int i = 0;i < n;i++){
		q.push(double(a[i]));
	}
	while(q.size() != 1){
		double a = q.top();
		q.pop();
		double b = q.top();
		q.pop();
		double c = (a+b)/2;
		q.push(c);
	}
	return (int)q.top();
}

int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d\n",getMaxLength());
}


