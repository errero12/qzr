#include<bits/stdc++.h>
using namespace std;
const int N = 3010;
int f[N][N];
int t[N][N];
int w[N][15];
int p[N];
int sump, ansum;
int n, k, sum;
int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> p[i];
		sump += p[i];
		for(int j = 1; j <= p[i]; ++j){
			cin >> w[i][j];
			if(j == p[i]){
				ansum += w[i][j];
			}
		}
	}	
	if(sump <= k){
		cout << ansum << endl;
		return 0;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= k; ++j){
			f[i][j] = f[i - 1][j];
			if(j == p[i] || (j - p[i] > 0 && f[i - 1][j - p[i]] != 0)){
				f[i][j] = max(f[i][j], f[i - 1][j - p[i]] + w[i][p[i]]);
			}
		}
	}
	for(int i = n; i >= 1; --i){
		for(int j = 1; j <= k; ++j){
			t[i][j] = t[i + 1][j];
			if(j == p[i] || (j -p[i] > 0 && t[i - 1][j - p[i]] != 0)){
				t[i][j] = max(t[i][j], t[i - 1][j - p[i]] + w[i][p[i]]);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= p[i]; ++j){
			sum = k - j;
			for(int k = 0; k <= sum; ++k){
				if((k == 0 || f[i - 1][k] != 0)&&(sum - k == 0 || t[i + 1][sum - k] != 0))
				ans = max(ans, w[i][j] + f[i - 1][k] + t[i + 1][sum - k]);
			}
		}
	}
	cout << ans << endl;
}