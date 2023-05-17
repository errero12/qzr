#include<bits/stdc++.h>
using namespace std;
int dp[110][110],mp[110][110];
int n, m;
int f(int x, int y){
	if(dp[x][y]) return dp[x][y];
	else{
		dp[x][y] = 1;
		if(x>1&&mp[x][y]<mp[x-1][y])dp[x][y] = max(dp[x][y], f(x-1,y)+1);
		if(y>1&&mp[x][y]<mp[x][y-1])dp[x][y] = max(dp[x][y], f(x,y-1)+1);
		if(x<n&&mp[x][y]<mp[x+1][y])dp[x][y] = max(dp[x][y], f(x+1,y)+1);
		if(y<m&&mp[x][y]<mp[x][y+1])dp[x][y] = max(dp[x][y], f(x,y+1)+1);
		return dp[x][y];
	}
}
int main (){
	cin >> n >> m;
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <=m; ++j){
			cin >> mp[i][j];
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <=m; ++j){
			ans = max(ans, f(i, j));
		}
	}
	cout << ans <<endl;
}
