#include <iostream> 
#include <cmath>
using namespace std;

#define NUM 20
int n;
//一维解向量X=(x1, x2, ..., xn),其中 xi为1~n的一个数，表示第i列皇后在第几行
int x[NUM]; 
int sum; 

inline bool Place(int t) 
{ 
	int i; 
	for (i=1; i<t; i++) 
		// 每一行都不相同 或者 不在一个对角线，任意对角线的斜率绝对值为1，两个点为(x[i], i)和[x[t], t]
		if ((abs(t-i) == abs(x[i]-x[t])) || (x[i] == x[t])) 
			return false; 
	return true; 
} 

void Backtrack(int t) 
{ 
	int i;
	if (t>n) //到达叶子结点，获得一个可行方案。累计总数，并输出该方案。
	{
		sum++;
		for (i=1; i<=n; i++) 
			printf(" %d", x[i]);
		printf("\n");
	}
	else
		for (i=1; i<=n; i++) 
		{
			x[t] = i;
			if (Place(t)) Backtrack(t+1);
		}
} 

int main() 
{ 
	while (cin>>n)
	{
		sum = 0;
		Backtrack(1);
		printf("Total= %d\n\n", sum);
	}
	return 0; 
} 
