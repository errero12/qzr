#include <cstdio>
using namespace std;

int A[11];
int N, M;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int solve() {
    int ans = 0;
    //二进制枚举
    for(int i = 1; i < (1 << N); i++) {
        int odd = 0, div = 1;
        for(int j = 0; j < N; j++)
            if((1 << j) & i) {
                odd++;
                div = lcm(div, A[j]); //同时被两个数整除，则必须是它们的最小公倍数
            }
        if(odd & 1)
            ans += M / div;
        else
            ans -= M / div;
    }
    return ans;
}

int main() {
    while(scanf("%d%d", &N, &M) != EOF) {
        for(int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        printf("%d\n", solve());
    }
    return 0;
}