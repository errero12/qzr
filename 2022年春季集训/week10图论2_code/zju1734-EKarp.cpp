#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 120
const int INF = 0x3f3f3f3f;

int cap[MAX][MAX];

/*
  1. 初始化剩余网络为原图；
  2. 对剩余网络按照层次图进行BFS，搜索增广路径，计算出瓶颈流量；
  3. 更新剩余网络的正向边和反向边。
 */

// s为超级源点，t为超级汇点
int EKarp(int s,int t)
{
	queue<int> Q;  //用于BFS算法搜索增广路径
	int flow[MAX][MAX]; //剩余网络
	int pre[MAX]; //增广路径结点
	int node[MAX]; //增广路径上的最小流
	int u,v;
	int maxflow = 0; //网络的最大流
	memset(flow,0,sizeof(flow));
	while (true)
	{
		Q.push(s);
		memset(node,0,sizeof(node));
		node[s] = INF;
		// BFS算法，搜索增广路径
		while(!Q.empty())
		{
			u = Q.front();
			Q.pop();
			for (v = 0; v <= t; v++)
				if (!node[v] && cap[u][v] > flow[u][v]) // 找到增广路径上的一个结点
				{
					Q.push(v);
					node[v] = min(node[u], cap[u][v]-flow[u][v]);
					pre[v] = u;
				}
		}
		//当瓶颈容量为0时，说明不存在增广路径，搜索结束
		if (node[t] == 0)
			break;
		//根据增广路径和瓶颈容量，更新剩余网络
		for (u = t; u != s; u = pre[u])
		{
			flow[pre[u]][u] += node[t]; // 修改反向边
			flow[u][pre[u]] -= node[t]; // 修改正向边
		}
		maxflow += node[t]; //总流量累加
	}
	return maxflow;
}

int main()
{
	int n, np, nc, m;
	int from, to, value;
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
	{
		memset(cap,0,sizeof(cap));
		while (m--)
		{
			scanf(" (%d,%d)%d",&from,&to,&value);
			cap[from][to] = value;
		}
		while (np--)
		{
			scanf(" (%d)%d",&from,&value);
			cap[n][from] = value;
		}
		while (nc--)
		{
			scanf(" (%d)%d",&from,&value);
			cap[from][n+1] = value;
		}
		printf("%d\n", EKarp(n, n+1));
	}
	return 0;
}
