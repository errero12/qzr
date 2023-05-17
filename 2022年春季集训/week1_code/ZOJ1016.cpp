#include <iostream>
#include <stack>
using namespace std;

stack<int> S;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{	
		int n;
		cin >> n;
		int p;
		int t = 0; //保存P序列中当前元素p的前序，初值为0
		for (int i = 1; i <= n; i++)
		{	
			cin >> p;
			// 将p -t个左括号入栈
			for (int j = 1; j <= p - t; j++) 
				S.push(-1);
			// 前面就是一个左括号
			if (S.top() == -1)
			{	
				i == 1 ? cout<<"1" : cout<<" 1";
				S.pop(); 
				S.push(1);
			}
			// 计算前面有多少个成对的括号
			else
			{	
				int iTop = S.top(); // 成对的括号数量
				S.pop();
				while (S.top() != -1) // 一直遇到左括号
				{	
					iTop += S.top(); 
					S.pop();
				}
				cout << " "<< iTop + 1; //加上自己一个
				S.pop();  //弹出 -1
				S.push(iTop + 1); //有iTop + 1个成对的括号
			}
			t = p; // 保存当前元素
		}
		cout<<endl;
		while (!S.empty()) S.pop(); // 堆栈清空
	}
	return 0;
}
