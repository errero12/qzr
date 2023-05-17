#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1000010;
ll d1[N], a[N];
int main(){
	int n;
	cin >> n;
	ll ans = -1111111111;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		d1[i] = max(a[i], a[i] + d1[i-1]);
		ans = max(ans, d1[i]);
	}
	cout << ans << endl;
}
