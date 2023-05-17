#include<iostream>
using namespace std;

#define NUM 1000
int n; //集装箱的数量
int c; //轮船的载重量
int w[NUM]; //集装箱的重量数组
int x[NUM]; //当前搜索的解向量
int r;  //剩余集装箱的重量
int cw; //当前轮船的载重量
int bestw; //当前最优载重量
int bestx[NUM]; //当前最优解

void Backtrack(int t)
{
	if(t>n)
	{
		if(cw>bestw)
		{
			for(int i=1; i<=n; i++) 
				bestx[i] = x[i];
			bestw = cw;
		}
		return;
	}
	r -= w[t];
	if(cw+w[t]<=c) //搜索左子树
	{
		x[t] = 1;
		cw += w[t];
		Backtrack(t+1);
		cw -= w[t];  //恢复状态
	}
	if(cw+r>bestw) //搜索右子树
	{
		x[t]=0;
		Backtrack(t+1);
	}
	r += w[t];
}

int main()
{
	while (scanf("%d%d", &c, &n)!=EOF) 
	{
		r = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d", &w[i]);
			r += w[i];
		}
		cw = 0;
		bestw = 0;
		Backtrack(1);
		printf("%d\n", bestw);
		for(int i=1;i<=n;i++)
			if (bestx[i]) printf("%d ", i);
		printf("\n");
	}
}
