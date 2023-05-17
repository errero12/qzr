#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

const int MAX = 205;
const int INF = 0x3f3f3f3f;
int nHouse, nMan, total;
int pre[MAX]; //增广路径
int cost[MAX][MAX]; //网络费用的邻接矩阵
int cap[MAX][MAX]; //网络容量的邻接矩阵
struct node
{
	int x, y;
}house[MAX], man[MAX];
/*
  man作为集合U，house作为集合V，把U到V所有连边记作(u,v)，费用就是cost[u][v],
  容量为cap[u][v] = 1，反向弧费用cost[v][u] = -cost[u][v]，构成了一个多源多汇的二分图。
  每一个多源多汇的二分图都有一个与之对应的单源单汇的网络流，由此构造一个超级源点s和超级汇点t，
  s与U中所有顶点相连，费用cost[s][u] = 0, 容量cap[s][u] = 1; t与V中所有顶点相连，费用cost[v][t] = 0, 容量cap[v][t] = 1。
  问题就转化为求这个单源单汇网络流的最小费用。
*/
//增加了超级源点0和超级汇点1
void make_map()
{
	memset(cap, 0, sizeof(cap));
	for (int i = 0; i < nMan; i++)
	{
		cap[0][i+2] = 1;
		cost[0][i+2] = 0;
	}
	for (int i = 0; i < nHouse; i++)
	{
		cap[nMan+i+2][1] = 1;
		cost[nMan+i+2][1] = 0;
	}
	for (int i = 0; i < nMan; i++)
		for (int j = 0; j < nHouse; j++)
		{
			cap[i+2][nMan+j+2] = 1;
			cost[i+2][nMan+j+2] = abs(man[i].x-house[j].x) + abs(man[i].y-house[j].y);
			cost[nMan+j+2][i+2] = -cost[i+2][nMan+j+2];
		}
}

bool SPFA()
{
	int d[MAX]; //最短路径中的距离数组
	bool vis[MAX]; //标记各点是否在队列中
	for (int i = 1; i <= total; i++) //初始化
	{
		d[i] = INF;
		vis[i] = false;
	}
	d[0] = 0;  //超级源点
	queue <int> q;
	q.push(0);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		// 枚举该点连接的每一条边，容量未饱和而且能够松弛
		for (int i = 1; i <= total; i++)
			if (cap[u][i] && d[i] > d[u] + cost[u][i])
			{
				d[i] = d[u] + cost[u][i];
				pre[i] = u;
				if (!vis[i])
				{
					vis[i] = true;
					q.push(i);
				}
			}
		vis[u] = false; 
	}
	// 找到一条当前费用和最小的增广路径
	if (d[1] < INF)
		return true;
	//超级汇点没有被调整，说明已不存在增广路径
	return false;
}

// 计算最小费用最大流
int MinCost_MaxFlow()
{
	int result = 0;
	while (SPFA()) // 当能够找到费用最小的增广路径
	{
		int minflow = INF; // 瓶颈容量
		for (int i = 1; i != 0; i = pre[i])
			minflow = min(minflow, cap[pre[i]][i]);
		//更新剩余网络
		for (int i = 1; i != 0; i = pre[i])
		{
			cap[pre[i]][i] -= minflow; //正向边
			cap[i][pre[i]] += minflow; //反向边
			result += cost[pre[i]][i] * minflow;
		}
	}
	return result;
}

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m), n && m)
	{
		char c;
		nHouse = nMan = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf(" %c", &c);
				if (c == 'H')
				{
					house[nHouse].x = i;
					house[nHouse].y = j;
					nHouse++;
				}
				else if (c == 'm')
				{
					man[nMan].x = i;
					man[nMan].y = j;
					nMan++;
				}
			}
		total = nHouse + nMan + 1;
		make_map();
		printf("%d\n", MinCost_MaxFlow());
	}
	return 0;
}
