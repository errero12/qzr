#include<bits/stdc++.h>
using namespace std;
int endd[310][310];
int noww[310][310];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
struct node{
	int step, x, y;
	node(int _step, int _x, int _y) :
		step(_step), x(_x), y(_y) {}
};
void Init(int x, int y){
	endd[x][y] = 1;
	endd[x + 1][y] = 1;
	endd[x][y + 1] = 1;
	if(x>0)endd[x - 1][y] = 1;
	if(y>0)endd[x][y - 1] = 1;
}
void _Init(int x, int y, int t){
	noww[x][y] = min(noww[x][y], t);
	noww[x + 1][y] = min(noww[x+1][y], t);
	noww[x][y + 1] = min(noww[x][y+1], t);
	if(x>0)noww[x - 1][y] = min(noww[x-1][y], t);
	if(y>0)noww[x][y - 1] = min(noww[x][y], t);
}
queue<struct node> Que;
int bfs(){
	Que.push(node(0, 0, 0));
	while(Que.size()){
		struct node nn = Que.front();
		Que.pop();
		int step = nn.step, x = nn.x, y = nn.y;
		for(int i = 0; i < 4; i++){
			//cout << step << endl;
			int tx = x + dir[i][0], ty = y + dir[i][1];
			if(tx < 0 || ty < 0)continue;
			if(endd[tx][ty] == 0) 
			{
				//cout << tx << " " << ty << endl;
				return step + 1;
			}
			if(noww[tx][ty] <= step + 1)continue;
			else{
				noww[tx][ty] = 0;
				Que.push(node(step + 1, tx, ty));
			}
		}
	}
	return -1;
}
int main (){
	int m;
	cin >> m;
	for(int i = 0; i < 310; i++){
		for(int j = 0; j < 310; j++)
		noww[i][j] = 1e6;
	}
	for(int i = 1; i <= m; i++){
		int x, y, t;
		cin >> x >> y >> t;
		Init(x, y);
		_Init(x,y,t);
	}
	cout << bfs() << endl;
}
