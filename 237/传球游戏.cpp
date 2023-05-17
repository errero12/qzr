#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[40][40];
int main (){
	int n, m;
	cin >> n >> m;
	if(m==1){
		cout << 0 << endl;
		return 0;
	}
	dp[1][0] = 1;
	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++){
			if(i==1)dp[i][j] = dp[n][j-1] + dp[i+1][j-1];
			else if(i==n)dp[i][j] = dp[i-1][j-1] + dp[1][j-1];
			else dp[i][j] = dp[i-1][j-1] + dp[i+1][j-1];
		}
	}
	cout << dp[1][m] << endl;
	cout << dp[1][0] << dp[2][1] << dp[3][1] << endl;
} 
