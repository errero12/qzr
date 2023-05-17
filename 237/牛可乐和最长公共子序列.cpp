#include<bits/stdc++.h> 
using namespace std;
int dp[5010][5010];
char a[5010], b[5010];
int main (){
	while(cin >> a+1 >> b+1){
		int la = strlen(a+1), lb = strlen(b+1);	
			for(int i = 1; i <= la; ++i){
		for(int j = 1; j <= lb; ++j){
			dp[i][j] = 0;
		}
	}

	if(a[1] == b[1]) dp[1][1] = 1;
	for(int i = 1; i <= la; ++i){
		for(int j = 1; j <= lb; ++j){
			if(a[i] != b[j])dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			else dp[i][j] = dp[i-1][j-1] + 1;
		}
	}
	cout << dp[la][lb] << endl;
	}

}
