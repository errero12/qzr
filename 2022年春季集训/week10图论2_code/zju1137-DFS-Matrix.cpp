#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 500
int n; //学生人数
int mp[MAX][MAX]; //同学关系邻接矩阵
int match[MAX]; // 匹配关系
int use[MAX]; //记录已覆盖顶点

//stu表示二分图左边的结点
bool DFS(int stu)
{
	// 搜索二分图右边的每个结点
	for(int i = 0; i < n; i++)
	{
		// 结点i未被覆盖，且与stu有边
		if(!use[i] && mp[stu][i])
		{
			use[i] = 1; // 标记为覆盖结点
			// 结点i是未匹配结点，或在增广路径上
			if(match[i] == -1 || DFS(match[i]))
			{
				match[i] = stu; // 更新匹配关系
				return true;
			}			
		}
	}
	return false;
}

// 匈牙利算法
int hungary()
{
	int num = 0; //匹配数
	memset(match, -1, sizeof(match));
	//对二分图左边的每个结点，搜索增广路径
	for(int i = 0; i < n; i++)
	{
		memset(use, 0, sizeof(use));
		// 找到了增广路径，结点i找到了一个匹配
		if(DFS(i))
			num++;
	}
	return n - num / 2;
}

int main()
{
	int a,b,m;
	while(scanf("%d",&n)!=EOF)
	{
		memset(mp,0,sizeof(mp));
		for(int i = 0; i < n; i++)
		{
			scanf("%d: (%d)",&a,&m);
			for(int j = 0; j < m; j++)
			{
				scanf("%d",&b);
				mp[a][b]=1;
			}
		}
		printf("%d\n",hungary());
	}
	return 0;
}
