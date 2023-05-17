#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[100010],d[100010],dd[100010];
int main (){
	int j = 1;
	int maxx = 0;
	while(cin >> d[j]){
		j++;
	} 
	//cout << j << endl;
	for(int i = 1; i < j; i++){
		dp[i] = 1;
		for(int k = i -1; k >= 1; k--){
			if(d[i] <= d[k]) dp[i] = max(dp[k] + 1,dp[i]);
		}
		maxx = max(maxx, dp[i]);
	}
	int minn = 0;
	for(int i = 1; i < j; i++){
		dd[i] = 1;
		for(int k = i -1; k >= 1; k--){
			if(d[i] >= d[k]) dd[i] = max(dd[k] + 1,dd[i]);
		}
		minn = max(minn, dd[i]);
	}
	cout << maxx <<endl << minn << endl;
} 
