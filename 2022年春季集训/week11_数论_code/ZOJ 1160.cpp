#include <cstdio>
using namespace std;

int main()
{
	int p,e,i,d;
	int N;
	scanf("%d", &N);
	while(N--)
	{	
		int iCase = 1;
		int M = 23 * 28 * 33;
		while (scanf("%d%d%d%d",&p,&e,&i,&d) && p != -1)
		{
			int n = (5544*p+14421*e+1288*i)%M;
			if (n<=d) n += M;
			printf("Case %d: the next triple peak occurs in %d days.\n",iCase++,n-d);
		}
		if(N)
            printf("\n");
	}
	return 0;
}
