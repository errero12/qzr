#include<iostream>
using namespace std;

#define NUM 100
int c; //背包的容量
int n; //物品的数量
int cw; //当前重量
int cv; //当前价值
int bestv; //当前最优解


struct Object{
	int w; //物品的重量
	int v; // 物品的价值
}Q[NUM]; // 物品的数量


void backtrack(int i)
{
	//到达叶子结点，更新最优解
	if (i+1>n) {
		if(cv > bestv) {
			bestv = cv; 
			return;
		}
	} else {
		for(int j = 0; j < 2; j++) {
			// 不放入背包
			if (j == 0) {
				backtrack(i+1);
			}
			else {
				if (cw+Q[i].w<=c) //放入背包
				{
					cw += Q[i].w;
					cv += Q[i].v;
					backtrack(i+1);
					cw -= Q[i].w;
					cv -= Q[i].v;
				}
			}
		}

	}

}

int main()
{
	while(scanf("%d",&c) && c)
	{
		cw = 0;
		cv = 0;
		bestv = 0;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&Q[i].w,&Q[i].v);
		}
		backtrack(0);
		printf("%d\n", bestv);
	}
	return 0;
}
