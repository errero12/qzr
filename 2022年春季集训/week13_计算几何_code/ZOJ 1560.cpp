// 题意：已知点 p1 p2 的坐标以及相对于 p 的角度，求 p 的坐标。
#include <cstdio>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);  //高精度圆周率
const double eps = 1e-8;       //偏差值


int sgn(double x) {  //判断x是否等于0
    if(fabs(x) < eps)  return 0;
    else return x < 0 ? -1 : 1;
}

int main() {
	int n;
	scanf("%d", &n);
	// 先求两直线方程，再求交点即可
	// 方程形式： cos(d)*x + (-sin(d))*y + c = 0
	while(n--) {
		int x1, y1, d1;
		scanf("%d%d%d", &x1, &y1, &d1);
		int x2, y2, d2;
		scanf("%d%d%d", &x2, &y2, &d2);
		double a1 = cos((double)d1 / 180 * pi);
		double b1 = -sin((double)d1 / 180 * pi);
		double c1 = -b1 * y1 - a1 * x1;
		double a2 = cos((double)d2 / 180 * pi);
		double b2 = -sin((double)d2 / 180 * pi);
		double c2 = -b2 * y2 - a2 * x2;
		// a1*x + b1*y + c1 = 0
		// a2*x + b2*y + c2 = 0
		// 交点：x=(c2*b1-c1*b2)/(a1*b2-a2*b1)
		// y=(c2*a1-c1*a2)/(b1*a2-a1*b2)
		double x = (c2*b1-c1*b2)/(a1*b2-a2*b1);
		double y = (c2*a1-c1*a2)/(b1*a2-a1*b2);
		printf("%.4lf %.4lf\n", x, y);
	}
	return 0;
}