#include<bits/stdc++.h>
using namespace std; 
int n, w[70];
int ans = 1e6;
int sum = 0, maxx = 0;
int dfs(int tra,int len,int count){
	if(count == n && len == 0){
		return 1;
	}
	int i = 1;
	int temp = 0;
	for(int i = 1; i <= n; i++){
		if(temp == w[i])continue;
		if(w[i] && len+w[i] <= tra){
			temp = w[i];
			w[i] = 0;
			if(dfs(tra, (len+temp)%tra, count + 1)){
				return 1;
			} 
			w[i] = temp;
		}
		else if(len+w[i] > tra){
			break;
		}
		
	}
	return 0;
}
int main (){
	cin >>n;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
		sum += w[i];
		maxx = max(w[i], maxx);
	}
	sort(w+1, w+1+n);
	for(int i = maxx; i <= sum; i++){
		if(sum%i==0)
		 	if(dfs(i,0,0)){
			cout << i << endl;
			return 0;
		}
	}
	
}
