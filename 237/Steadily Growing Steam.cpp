//dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-t[i]][k], dp[i-1][j-2*t[i]][k-1])
#include<bits/stdc++.h>
using namespace std;
int t[110], v[110];
int dp[110][10010][110];
int main (){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> v[i] >> t[i];
	}
	int ans = -10000;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= 10000; ++j){
			for(int z = 0; z <= k; ++z){
				dp[i][j][z] = dp[i-1][j][z];
				dp[i][j][z] = max(dp[i][j][z], dp[i-1][abs(j-t[i])][z] + v[i]);
				if(z>0)dp[i][j][z] = max(dp[i][j][k], dp[i-1][abs(j-2*t[i])][z-1] + v[i]);
			if(j==0){
				ans = max(ans,dp[i][j][z]);
			}
			}
		}
	}
	cout << ans << endl;
}
