#include <iostream>
using namespace std;

#define NUM 100
int n; // 图的顶点
int m; // 可用颜色数量
int a[NUM][NUM]; // 图的邻接矩阵
int x[NUM]; // 当前的解向量
int sum ; // 已经找到的可m着色的方案数量

bool Same(int t)
{
	int i;
	for(i=1; i<=n; i++ )
		if( (a[t][i] == 1) && (x[i] == x[t]) )
			return false;
	return true;
}

void BackTrack(int t )
{
	int i;
	if(t > n) // 到达叶子结点，获得一个着色方案
	{
		sum++ ;
		for(i=1; i<=n ;i++)
			printf("%d ",x[i]);
		printf("\n") ;
	}
	else 
		for(i=1; i<=m; i++)// 搜索当前扩展结点的m个孩子
		{
			x[t] = i;
			if(Same(t))	BackTrack(t+1);
			x[t] = 0;
		}
}

int main()
{
	scanf("%d %d",&n,&m);
	memset(a,0,sizeof(a));
	int b ,e ;
	while(scanf("%d%d",&b,&e) && (b||e) )
	{
		a[b][e] = 1 ;
		a[e][b] = 1 ;
	}
	sum = 0;
	BackTrack(1);
	printf("Total=%d\n",sum ) ;
	return 0;
}
