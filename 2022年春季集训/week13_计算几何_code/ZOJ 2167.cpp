// 平面上有若干点，求半径为1的圆能包含最多几个点。
#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 1e-8; 
const int maxn = 305;

struct Point {
	double x, y;
};

double Distance(Point A, Point B) {
	return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

int sgn(double x) {
    if(fabs(x) < eps)
    	return 0;
    return x < 0 ? -1 : 1;
}

Point p[maxn];

int main() {
	int N;
	while(scanf("%d", &N) && N) {
		for(int i = 0; i < N; i++)
			scanf("%lf %lf", &p[i].x, &p[i].y);
		int ans = 1;
		for(int i = 0; i < N; i++) {
			for(int j = i + 1; j < N; j++) {
				double l = Distance(p[i], p[j]);
                if (l > 2)
                    continue;
                Point c;
                c.x = (p[i].x + p[j].x) / 2;
                c.y = (p[i].y + p[j].y) / 2;
                double angle = atan2(p[i].x - p[j].x, p[j].y - p[i].y);
                double d = sqrt(1 - l/2*l/2);
                Point center;
                center.x = c.x + d * cos(angle);
                center.y = c.y + d * sin(angle);
                
                int cnt = 2;
                for(int k = 0; k < N; k++) {
                    if (k != i && k != j) {
                        double dis = Distance(p[k], center);
                        if (sgn(dis - 1) <= 0) {
						    cnt++;
					    }
                    }
                }
				if (cnt > ans)
					ans = cnt;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}