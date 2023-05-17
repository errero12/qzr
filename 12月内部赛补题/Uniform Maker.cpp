#include<bits/stdc++.h>
using namespace std;
char s[200];
int a[200][30];
int aa[200];
int n, m;
int main(){
	cin >> n >> m;
	int ans = n*m;
	for(int i = 1; i <= n; ++i){
		cin >> s;
		for(int j = 0; j < m; ++j){
			a[j][s[j]-'a']++;
		}
	}
	for(int j = 0; j < m; ++j){
		for(int k = 0; k < 26; ++k){
			aa[j] = max(aa[j], a[j][k]);
		}
		ans -= aa[j];
	}
	cout << ans << endl;
}