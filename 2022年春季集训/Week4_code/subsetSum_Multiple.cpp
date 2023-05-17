#include<iostream>
using namespace std;

#define NUM 10000
int n; // 集合s中的元素个数
int c; // 子集和的目标值
int cw; // 当前的子集和
int bestw; //当前的最优值
int w[NUM]; // 集合s中的元素
int x[NUM]; // 构成当前子集和的元素
int r;      //集合S中剩余的所有元素和
bool flag; // 获得最优的标志

void backtrack(int t)
{
	if(t>n)
	{
		// 获得最优解
		if(cw==c)
		{
			for(int i=1; i<=n; i++)
				if (x[i]) printf("%d ",w[i]);
			printf("\n");
			flag = false;
		}
		return;
	}
	// 更新剩余的所有元素和
	r -= w[t];
	if (cw+w[t]<=c)
	{
		x[t] = 1;
		cw += w[t];
		backtrack(t+1);
		cw -= w[t]; // 恢复状态
	}
	if (cw+r>bestw) // 搜索右子树
	{
		x[t] = 0;
		backtrack(t+1);
	}
	r += w[t]; // 恢复状态
}

int main()
{
	while(scanf("%d%d",&n,&c) && (n||c))
	{
		r = 0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &w[i]);
			r += w[i];
		}
		cw = 0;
		bestw = 0;
		flag = true;
		backtrack(1);
		if (flag) printf("No Solution!\n");
	}
	return 0;
}
