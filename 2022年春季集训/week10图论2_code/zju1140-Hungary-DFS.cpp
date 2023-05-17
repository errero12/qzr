#include<cstdio>
#include<cstring>

using namespace std;

#define P 110
#define N 310
int p; //课程数
int n; //学生数
int mp[P][N]; //选课关系邻接矩阵
int match[N]; //匹配关系
bool use[N]; //记录已覆盖顶点

// u表示二分图左边的结点
bool DFS(int u)
{
	for (int v = 1; v <= n; ++v)
	{
		if (!use[v] && mp[u][v]) //结点v是未覆盖点，且与u有边
		{
			use[v] = true;
			if (match[v] == -1 || DFS(match[v]))
			{
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	//匹配的课程数
	int course = 0;
	//对每门课程，搜索增广路径
	for (int i = 1; i <= p; ++i)
	{
		memset(use, false, sizeof(use));
		if (DFS(i)) //找到了增广路径，课程结点i找到了一个匹配
			course++;
	}
	// 根据已知的选修关系，找到课程与学生的最大匹配数
	return course;
}

int main()
{
	int iCase;
	scanf("%d", &iCase);
	while (iCase--)
	{
		int count;
		int student;
		memset(mp, 0, sizeof(mp));
		memset(match, -1, sizeof(match));
		scanf("%d%d", &p, &n);
		for (int i = 1; i <= p; ++i)
		{
			scanf("%d", &count);
			for (int j = 1; j <= count; ++j)
			{
				scanf("%d", &student); 
				mp[i][student] = 1;
			}
		}
		printf("%s\n", hungary() == p?"YES":"NO");
	}
	return 0;
}
