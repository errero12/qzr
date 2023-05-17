#include<bits/stdc++.h>
using namespace std;
int n, m, q;
int xz, yz;
int xt, yt;
char mg[310][310];
int cs[310][310];
int ans[310][310];
int akk;
map<int,vector<pair<int,int> > > trans, _trans;
struct node{
	int x, y, step;
	node(int _x, int _y, int _step) : 
		x(_x), y(_y), step(_step) {}
};
int fx[9] = {0,1,0,-1,0,0,1,0,-1};
queue<node> qe;
int bfs(){
	qe.push(node(xz, yz, 0));
	mg[xz][yz] = 'F';
	ans[xz][yz] = 0;
	while(qe.size()){
		auto cur = qe.front();
		qe.pop();
		for(int i = 1; i < 8; i += 2){
			int x = cur.x + fx[i], y = cur.y + fx[i+1], step = cur.step;
			if(x >= 0 && x < n && y >= 0 && y < m){
				if(mg[x][y] == '.'){
					mg[x][y] = 'F';
					ans[x][y] = min(step + 1, ans[x][y]);
					if(step+1 < akk)
					qe.push(node(x,y,step+1));
				}
				else if(mg[x][y] == 'F' && ans[x][y] > step + 1){
					ans[x][y] = min(step + 1, ans[x][y]);
					if(step+1 < akk)
					qe.push(node(x,y,step+1));
				}
				else if(mg[x][y] == 'T'){
					akk = min(akk, step + 1);
				}
			}
			
		}
		if(cs[cur.x][cur.y]){
			auto ak = trans[cs[cur.x][cur.y]];
			for(int i = 0; i < ak.size(); i++){
				int x = ak[i].first, y = ak[i].second, step = cur.step;
				if(x >= 0 && x < n && y >= 0 && y < m){
				if(mg[x][y] == '.'){
					mg[x][y] = 'F';
					ans[x][y] = min(step + 3, ans[x][y]);
					if(step+3 < akk)
					qe.push(node(x,y,step+3));
				}
				else if(mg[x][y] == 'F' && ans[x][y] > step + 3){
					ans[x][y] = min(step + 3, ans[x][y]);
					if(step+3 < akk)
					qe.push(node(x,y,step+3));
				}
				else if(mg[x][y] == 'T'){
					akk = min(akk, step + 3);
				}
			}
			}
		}
	}
	if(akk != 1e8) return akk;
	return -1;
}
int main (){
	while(cin >> n >> m >> q){
		int count = 0, _count = 0;
		for(int i = 0; i <= 309; i++){
			for(int j = 0; j <= 309; j++){
				cs[i][j] = 0;
				ans[i][j] = 1e8;
			}
		}
		trans.clear();
		queue<node> em;
		swap(qe, em);
		akk = 1e8;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> mg[i][j];
				if(mg[i][j] == 'S'){
					xz = i, yz = j;
				}
			}
		}
		for(int i = 1; i <= q; i++){
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if(mg[x1][y1] != '#' && mg[x2][y2] != '#' && x1 >= 0 && x1 < n && x2 >= 0 && x2 < n && y1 >= 0 && y1 < m && y2 >= 0 && y2 < m){
				int key;
				if(cs[x1][y1]){
					key = cs[x1][y1];
				}
				else {
					count ++;
					key = count;
					cs[x1][y1] = count;
				}
				trans[key].push_back({x2, y2});
			}
		}
		cout << bfs() << endl;
	}
}
