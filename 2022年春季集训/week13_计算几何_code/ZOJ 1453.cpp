#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 105;
const double eps = 1e-8;

struct Point {
	int x, y;
	Point(){}
	Point(int x, int y):x(x), y(y) {}
	Point operator + (Point B) {
		return Point(x + B.x, y + B.y);
	}
	Point operator - (Point B) {
		return Point(x - B.x, y - B.y);
	}
	bool operator == (Point B) {
		return x == B.x && y == B.y;
	}
	bool operator < (Point B) {
		return x < B.x || (x == B.x && y < B.y);
	}
};

int Cross(Point A, Point B) {
	return A.x * B.y - A.y * B.x;
}

double Distance(Point A, Point B) {
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

int Convex_hull(Point *p, int n, Point *ch) {
	sort(p, p + n); //排序
	n = unique(p, p + n) - p; // 去重
	int v = 0;
	//求下凸包，如果p[i]是右拐弯的，这个点不在凸包上，往回退
	for(int i = 0; i < n; i++) {
		while(v > 1 && Cross(ch[v-1] - ch[v-2], p[i] - ch[v-2]) <= 0)
			v--;
		ch[v++] = p[i];
	}
	int j = v;
	//求上凸包
	for(int i = n - 2; i >= 0; i--) {
		while(v > j && Cross(ch[v-1] - ch[v-2], p[i] - ch[v-2]) <= 0)
			v--;
		ch[v++] = p[i];
	}
	if (n > 1)
		v--;
	return v;
}

Point p[maxn], ch[maxn];
int main() {
	int n;
	while(scanf("%d", &n) && n) {
		for(int i = 0; i < n; i++) {
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		int v = Convex_hull(p, n, ch);
		ch[v] = ch[0];
		double ans = 0;
		for(int i = 0; i < v; i++)
			ans += Distance(ch[i], ch[(i+1)%v]);
		printf("%.2lf\n", ans);
	}
	return 0;
}