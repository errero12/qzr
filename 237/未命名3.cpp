#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll a, b;
ll f(ll x, ll y){
	ll count = 0;
	ll i = x, j = y;
	while(i%2 == 0 && j%2 == 0){
		count++;
		j /= 2;
		i /= 2;
		swap(i,j);
	}
	a = i, b = j;
	return count;
}
int main (){
	int T;
	cin >> T;
	while(T--){
		cin >> a >> b;
		ll ans = 0;
		ll r = f(a, b);
		//cout << a << " " << b <<" " << r << endl;
		if(a < b){
			ans++;
		}
			ans += r;
			r = ans/2 + 1;
			ans = ans % 2;
			cout << r << ' ' << ans << endl;
	}
}
