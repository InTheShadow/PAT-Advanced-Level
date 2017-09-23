#include<cstdio>
#include<queue>
using namespace std;

const int MAXM = 1290;
const int MAXN = 130;
const int MAXL = 61;

int M,N,L,T;
int matrix[MAXM][MAXN][MAXL];
bool inq[MAXM][MAXN][MAXL] = {false};

struct Node{
	int x,y,z;
}node;


int xi[6] = {1,-1,0,0,0,0};
int yi[6] = {0,0,1,-1,0,0};
int zi[6] = {0,0,0,0,1,-1};

bool judge(int x,int y,int z){
	if(x < 0 || x >= M || y < 0 || y >= N
	 || z < 0 || z >= L ) return false;
	if(matrix[x][y][z] == 0||inq[x][y][z] == true) return false;
	return true;
}

int bfs(int x,int y,int z){
	queue<Node> q;
	inq[x][y][z] = true;
	node.x = x,node.y = y,node.z = z;
	q.push(node);
	int res = 0;
	while(!q.empty()){
		Node top = q.front();
		q.pop();
		res++;
		for(int i = 0; i < 6;i++){
			int newx = top.x + xi[i];
			int newy = top.y + yi[i];
			int newz = top.z + zi[i];
			if(judge(newx,newy,newz)){
				node.x = newx,node.y = newy,node.z = newz;
				q.push(node);
				inq[newx][newy][newz] = true;
			} 
		}
	}
	if(res >= T) return res;
	else return 0;
}

int main(){
	scanf("%d%d%d%d",&M,&N,&L,&T);
	for(int z = 0; z < L;z++){
		for(int x = 0; x < M;x++){
			for(int y = 0; y < N;y++){
				scanf("%d",&matrix[x][y][z]);
			}
		}
	} 
	
	int ans = 0;
	for(int z = 0; z < L;z++){
		for(int x = 0; x < M;x++){
			for(int y = 0; y < N;y++){
				if(matrix[x][y][z] == 1 && inq[x][y][z] == false) 
					ans += bfs(x,y,z);
			}
		}
	} 
	printf("%d\n",ans);
	return 0;
}

