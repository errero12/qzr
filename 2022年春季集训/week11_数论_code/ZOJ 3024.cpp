#include <iostream>
#include <cstring>
using namespace std;
const int maxN = 300000 + 1;

int res[maxN];
bool visit[maxN];
int main() {
    int n;
    while(cin >> n && n != 1) {
        memset(visit, false, sizeof visit);
        int k = 0;
        for(int i = 2; i <= n; i++) {
            if ((i % 7 == 1 || i % 7 == 6) && n % i == 0 && !visit[i]) {
                res[k++] = i;
                for(int j = 2 * i; j <= n; j += i)
                    visit[j] = true;
            }
        }
        cout<< n << ":";
        for(int i = 0; i < k; i++)
            cout << " " << res[i];
        cout << endl;
    }
    return 0;
}