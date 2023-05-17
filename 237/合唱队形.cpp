#include<bits/stdc++.h>
using namespace std;
int d1[110], d2[110], a[110];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		d1[i] = 1;
		for(int j = i-1; j >= 1; j--){
			if(a[i] > a[j])d1[i] = max(d1[i],d1[j]+1);
		}
	}
	for(int i = n; i >= 1; i--){
		d2[i] = 1;
		for(int j = i+1; j <= n; j++){
			if(a[i] > a[j])d2[i] = max(d2[i], d2[j]+1);
		}
	}
	int ans = 0; 
	for(int i = 1; i <= n; ++i){
		ans = max(ans, d1[i]+d2[i]-1);
	}
	cout << n - ans << endl;
}
