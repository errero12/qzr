#include<bits/stdc++.h>
using namespace std;
int a[53];
map<int,int> ar[4];
int aa[4][14]; 
int num[4];
int pre[4];
#define ll long long
int main (){
	memset(num, 13, sizeof(num));
	for(int i = 1; i <= 13; ++i){
		int x;
		cin >> x;
		ar[0][x] ++;	
	}
	for(int i = 1; i <= 13; ++i){
		int x;
		cin >> x;
		ar[1][x] ++;	
	}
	for(int i = 1; i <= 13; ++i){
		int x;
		cin >> x;
		ar[2][x] ++;		
	}
	for(int i = 1; i <= 13; ++i){
		int x;
		cin >> x;
		ar[3][x] ++;
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; ++i){
		char c;
		cin >> c;
		int x, y;
		if(c == 'S'){
			memset(pre, 0, sizeof(pre));
			memset(aa, 0, sizeof(aa));
			cin >> x >> y;
			for(int j = 1; j <= y; ++j){
				int z;
				cin >> z;
				aa[i%4][z] ++;
				ar[i%4][z] --;
			}
			pre[i%4] = y;
		}
		else if(c == '!'){
			cin >> y;
			for(int j = 1; j <= y; ++j){
				int z;
				cin >> z;
				aa[i%4][z] ++;
				ar[i%4][z] --;
			}
			pre[i%4] = y;
		}
		else if(c == '?'){
			if(pre[(i-1)%4] != aa[(i-1)%4][x]){
				for(int k = 1; k <= 13; ++k){
					ar[(i-1)%4][k] += (aa[0][k]+aa[1][k]+aa[2][k]+aa[3][k]);
				}
			}
			else{
				for(int k = 1; k <= 13; ++k){
					ar[(i)%4][k] += (aa[0][k]+aa[1][k]+aa[2][k]+aa[3][k]);
				}
			}
		}
	}
	for(int i = 0; i <= 3; i++){
		for(int j = 1; j <= 13; ++j){
			for(int k = 1; k <= ar[i][j]; ++k){
				cout << j << ' ';
			}
		}
		cout << endl;
	}
}
