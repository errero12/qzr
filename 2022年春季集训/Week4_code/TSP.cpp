#include <iostream>
using namespace std;

#define NUM 100
int n; // 顶点数
int m; // 边数
int a[NUM][NUM]; //邻接矩阵
int x[NUM]; //当前解
int bestx[NUM]; //当前最优解向量
int cc;  // 当前费用
int bestc; // 当前最优值
int NoEdge = -1; // 无边标记

//排列数问题
void Backtrack(int t)
{
	if(t==n)
	{
		// 如果点n-1到n以及点n到点1都有路线，且这条回路的费用小于bestc或者bestc是初始状态
		if(a[x[n-1]][x[n]]!= NoEdge && a[x[n]][1]!= NoEdge && 
			(cc + a[x[n-1]][x[n]]+a[x[n]][1]<bestc||bestc== NoEdge))
		{
			for(int i=1; i<=n; i++)
				bestx[i] = x[i];
			bestc = cc + a[x[n-1]][x[n]] + a[x[n]][1];
		}
		return;
	}
	else 
	{
		for(int i=t; i<=n; i++)
		{
			// 剪枝
			if(a[x[t-1]][x[i]]!= NoEdge &&
				(cc + a[x[t-1]][x[i]]< bestc||bestc == NoEdge)) 
			{
				swap(x[t],x[i]);
				cc += a[x[t-1]][x[t]];
				Backtrack(t+1);
				cc -= a[x[t-1]][x[t]];
				swap(x[t],x[i]);
			}
		}
	}
}

int main() 
{
	int i, j;
	int from, to, length;
	while (scanf("%d%d", &n, &m) && n) 
	{
		for (i=0; i<NUM; i++)
			for (j=1; j<NUM; j++)
				a[i][j] = NoEdge;
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &from, &to, &length);
			a[from][to] = length;
			a[to][from] = length;
		}
		bestc = NoEdge;
		// 初始化为 1 ~ n的顺序排列
		for(i=1; i<=n; i++)
			x[i] = i;
		Backtrack(2);
		for(j=1; j<=n; j++)
			printf("%d ", bestx[j]);
		printf("\n%d\n", bestc);
	}	
	return 0;
}
