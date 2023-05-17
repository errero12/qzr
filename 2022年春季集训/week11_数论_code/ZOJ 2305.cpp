#include <iostream>
typedef long long ll;
using namespace std;
ll gcd (ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b); 
}
void extend_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    extend_gcd(b, a % b, x, y);
    ll tmp = x;
    x = y;
    y = tmp - (a/b)*y;
}
ll mod_inverse(ll a, ll m) {
    ll x, y;
    extend_gcd(a, m, x, y);
    return (m + x % m) % m;
}
// c*x % 2^k = (b - a) % 2^k
int main() {
    ll a, b, c, k;
    while(cin >> a >> b >> c >> k) {
        if (a == 0 && b == 0 && c == 0 && k == 0) break;
        ll mod = (ll)1 << k;
        ll d;
        if (c < mod)
            d = gcd(mod, c);
        else
            d = gcd(c, mod);
        if ((b-a) % d) {
            cout << "FOREVER\n";
        } else {
        	ll x, y;
            extend_gcd(c, mod, x, y);
            ll t = mod / d;
            ll ans = ((b - a) * x / d  % t + t) % t; 
            cout << ans << endl;
        }
    }
    return 0;
}