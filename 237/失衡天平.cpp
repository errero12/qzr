#include<bits/stdc++.h>
using namespace std;
const int N = 105*100 + 5;
int a[110], dp[110][2*N];
int main (){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= 105*100 + 5; ++j){
		dp[i][j] = dp[i - 1][j];
      dp[i][j] = max(dp[i][j], dp[i - 1][abs(j - a[i])] + a[i]);
      dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i]] + a[i]);
		}
	}
	  int ans = -1;
  for(int i = 0; i <= m; i++) ans = max(ans, dp[n][i]); 
  cout << ans << "\n";
  return 0;
}
