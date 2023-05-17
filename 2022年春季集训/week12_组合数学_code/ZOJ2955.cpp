#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int dp[10005], w[105];
/* 鸽笼原理+完全背包
推理：给n个整数a1,a2,a3…an,存在一段连续的区间，使区间和能够整除n。
证明：前缀和有（n+1)值，根据鸽巢原理，存在两个前缀和模n相等，即二者相减为0，故为这两个数之间的连续区间。
求k1*a1 + k2*a2 + k3*a3 + ... + kn*an == N.
所以k1+k2+k3+...+kn < an.（大于an必能用M*an代替，M为正整数）
N的最大值为an * an = 10000
*/
int main() {
    // 0 < M < 100,  1 < N <= 1e9, every possible score is (0, 100)
    int T, M, N;
    cin >> T;
    while(T--) {
        cin >> M >> N;
        for(int i = 1; i <= M; i++)
            cin >> w[i];
        sort(w + 1, w + 1 + M);
        int ans = 0;
        int maxW = w[M] * w[M];
        if (N >= maxW) {
            ans += N / maxW * w[M];
            N %= maxW;
        }
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i <= M; i++)
            for(int j = w[i]; j <= N; j++)
                if (dp[j - w[i]] != INF)
                    dp[j] = min(dp[j], dp[j - w[i]] + 1);
        if(dp[N] == INF)
            cout <<"-1\n";
        else
            cout << ans + dp[N] << endl;
    }
    return 0;
}