#include <cstdio>
#include <cstring>
using namespace std;

const int maxN = 1001;
int c1[maxN], c2[maxN];

int val[11], num[11];
int n, m;

int gen() {
    memset(c1, 0, sizeof(c1));
    memset(c2, 0, sizeof(c2));
    //初始化第一个多项式
    for(int i = 0; i <= num[0] && i * val[0] <= n; i++)
        c1[i * val[0]] = 1;
    for(int i = 1; i < m; i++) { //从第二部分开始展开 
        for(int j = 0; j <= n; j++)
            for(int k = 0; j + k * val[i] <= n && k <= num[i]; k++)
                c2[j + k * val[i]] += c1[j];

        for(int j = 0; j <= n; j++){
            c1[j] = c2[j];
            c2[j] = 0;
        }
    }
    return c1[n];
}

int main() {
    int caseN = 0;
    while(scanf("%d%d", &n, &m) != EOF) {
        if (caseN > 0)
            printf("\n");
        for(int i = 0; i < m; i++)
            scanf("%d%d", &val[i], &num[i]);
        caseN++;
        printf("%d\n", gen());
    }
    return 0;
}