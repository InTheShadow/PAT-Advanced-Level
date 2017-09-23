#include<cstdio>
using namespace std;

void dfs(int index,bool** temp,bool*visited,int n){
	visited[index] = true;
	for(int i = 0;i<n;i++){
		if(!visited[i] && temp[index][i]) {
			dfs(i,temp,visited,n); 
		}
	}
}

int main(){
	int n,m,k;
	//read n,m,k and malloc 
	scanf("%d%d%d",&n,&m,&k);
	bool** path = new bool*[n];
	for(int i = 0;i < n;i++){
		path[i] = new bool[n];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j<n;j++) {
			path[i][j] = false;
		}
	}
	bool* visited = new bool[n];

	//read path 
	int from,to;
	for(int i = 0;i < m;i++){
		scanf("%d%d",&from,&to);
		path[from-1][to-1] = true;
		path[to-1][from-1] = true;
	}
	
	//read concern city index and get repair number
	for(int i = 0;i<k;i++){
		//scan city
		int city;
		scanf("%d",&city);
		city--;	
		//init visit table and close temp table
		for(int i = 0; i< n;i++) {
			visited[i] = false;
		}
		visited[city] = true;
		//get repairnum in dfs
		int count = 0;
		for(int i = 0;i<n;i++){
			if(!visited[i]) {
				dfs(i,path,visited,n);
				count++;
			}
		}
		printf("%d\n",count-1);
	} 

	
	//delete visit table¡¢ path table and repair_num 
	for(int i = 0;i < n;i++){
		delete[] path[i];
	}	
	delete[] path;
	delete[] visited;
	
}
