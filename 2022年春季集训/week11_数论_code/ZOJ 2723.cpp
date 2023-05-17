#include <iostream>
using namespace std;
bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
int main() {
    int n;
    while(cin >> n) {
        if(isPrime(n)) {
            cout << "No\n";
        } else {
            bool ok = false;
            for(int i = 2; i * i <= n; i++) {
                if (isPrime(i) && n % i == 0) {
                    int r = n / i;
                    if (isPrime(r)) {
                        ok = true;
                        break;
                    }
                }
            }
            if (ok)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}
