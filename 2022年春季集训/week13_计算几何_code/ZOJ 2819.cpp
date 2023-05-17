#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 501;
const int maxm = 51;

const double eps = 1e-8;

struct PointS {
    double x, y, z;
};

struct PointT {
    double x, y, z, q;
};

PointS stars[maxn];
PointT telescopes[maxm];

double Dot(PointS A, PointT B) {
    return A.x*B.x+A.y*B.y+A.z*B.z;
}

double LenS(PointS A){
    return sqrt(A.x*A.x+A.y*A.y+A.z*A.z);
}

double LenT(PointT A){
    return sqrt(A.x*A.x+A.y*A.y+A.z*A.z);
}

double Angle(PointS A,PointT B){
    return acos(Dot(A,B)/LenS(A)/LenT(B));
}

int main() {
    int n, m;
    while(scanf("%d", &n) && n > 0) {
        for(int i = 0; i < n; i++)
            scanf("%lf %lf %lf", &stars[i].x, &stars[i].y, &stars[i].z);
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
            scanf("%lf %lf %lf %lf", &telescopes[i].x, &telescopes[i].y, &telescopes[i].z, &telescopes[i].q);
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if (telescopes[j].q - Angle(stars[i], telescopes[j]) > eps) {
                    ans++;
                    break;
                }
        printf("%d\n", ans);
    }
    return 0;
}
