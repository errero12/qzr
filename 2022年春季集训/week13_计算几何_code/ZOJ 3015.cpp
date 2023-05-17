#include <cstdio>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);

int main() {
    double k, h, a, b;
    while(scanf("%lf %lf %lf %lf", &k, &h, &a, &b) != EOF) {
        k = k / 180 * pi; 
        // 斜边的直线方程：y = -tan(k)*x + h
        // 过(b, 0)，斜率为1/tan(k)的直线方程为 y = 1/tan(k)*x - b/tan(k)
        // 它们的交点(p1, p2), p1 = (h + b/tan(k))/(tan(k) + 1/tan(k)), p2 = h - tan(k)*p1
        double p1 = (h + b/tan(k)) / (tan(k) + 1/tan(k));
        double p2 = h - tan(k) * p1;
        // 点(b, 0)关于(p1, p2)的对称点为(2*p1-b, 2*p2)
        // 过点(0, a)和点(2*p1-b, 2*p2)的直线方程为 y = (2*p2 - a)/(2*p1 - b) * x + a
        // 求方程 y = (2*p2 - a)/(2*p1 - b) * x + a 和 y = -tan(k)*x + h的交点C(c1, c2)
        // c1 = (h-a)/((2*p2-a)/(2*p1-b) + tan(k)), c2 = h - tan(k) * c1
        // ans = |(0,a), C| + |C, (b,0)|
        double c1 = (h-a)/((2*p2-a)/(2*p1-b) + tan(k));
        double c2 = h - tan(k) * c1;
        double ans = sqrt(c1*c1 + (c2-a)*(c2-a)) + sqrt((c1-b)*(c1-b) + c2*c2);
        printf("%.2lf\n", ans);
    }
    return 0;
}