#include<bits/stdc++.h>
using namespace std;
int main (){
	double a = 0, b = 0, a0 = 0, b0 = 0;
	
	int cp, p, gr, g, m, sum;
	cin >> cp >> p >> gr >> g >> m;
	sum = cp + p + gr + g + m;
	a += sum;
	a0 += cp + p + 0.8*gr + 0.5*g;
	cin >> cp >> p >> gr >> g >> m;
	sum = cp + p + gr + g + m;
	a += sum*2.0;
	a0 += (cp + p + 0.8*gr + 0.5*g)*2.0;
	cin >> cp >> p >> gr >> g >> m;
	sum = cp + p + gr + g + m;
	a += sum*3.0;
	a0 += (cp + p + 0.8*gr + 0.5*g)*3.0;
	cin >> cp >> p >> gr >> g >> m;
	sum = cp + p + gr + g + m;
	a += sum*5.0;
	a0 += (cp*5.0 + p*5.0 + 2.5*gr + 2.0*g);
	b += sum*1.0000000;
	b0 += cp + p*0.5 + 0.4*gr + 0.3*g;
	double ans = (a0/a)*100 + (b0/b);
	printf("%.12lf\n", ans);
} 
