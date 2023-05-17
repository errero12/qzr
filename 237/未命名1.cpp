#include<bits/stdc++.h>
using namespace std;
int a[100100];
#define ll long long
int main (){
	int n, k;
	cin >> n >> k;
	int key = 0;
	int len = n - k + 1; 
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == n)key = i;
	}
	int ans = 0;
	if((n-1)%(k-1))ans += 1;
	ans += (n-1)/(k-1);
	cout << ans << endl;
}
