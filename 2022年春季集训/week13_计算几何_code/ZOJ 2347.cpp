#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1005;

struct Point {
    int x, y;
    bool operator < (const Point& r) const {
        return x < r.x || (x == r.x && y < r.y);
    }
};

Point p[maxn];

int main() {
    int N;
    scanf("%d", &N);
    while(N--) {
        int n;
        while(scanf("%d", &n) && n > 0) {
            for(int i = 0; i < n; i++)
                scanf("%d %d", &p[i].x, &p[i].y);
            sort(p, p+n);
            int cnt = 0;
            // p1, p2为正方形的两个点，逆时针旋转90度去计算另外两个点p3, p4
            // 向量p2p1为u(x2-x1, y2-y1)，逆时针旋转90度的向量v为(y1-y2, x2-x1)
            // p3 = p2 + v = (x2+y1-y2, y2+x2-x1);
            // p4 = p1 + v = (x1+y1-y2, y1+x2-x1).
            for(int i = 0; i < n; i++)
                for(int j = i + 1; j < n; j++) {
                    Point t;
                    t.x = p[j].x + p[i].y - p[j].y;
                    t.y = p[j].y + p[j].x - p[i].x;
                    if(!binary_search(p, p+n, t))
                        continue;
                    t.x = p[i].x + p[i].y - p[j].y;
                    t.y = p[i].y + p[j].x - p[i].x;
                    if(!binary_search(p, p+n, t))
                        continue;
                    cnt++;
                }
            //这里需要cnt/2是因为一个正方形按逆时针枚举两个点，会被重复计算
            printf("%d\n", cnt / 2);
        }
        if (N > 0) {
            printf("\n");
        }
    }
    return 0;
}