#include<bits/stdc++.h>
using namespace std;
string a,b;
int A[26],B[26];
int main(){
	int T;cin>>T;
	while(T--){
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			A[a[i]-'a']++;
		}
		for(int i=0;i<b.size();i++){
			if(b[i]>='a'&&b[i]<='z'&&B[b[i]]>=0){
				B[b[i]]++;
			}
			if(b[i]<='Z'&&b[i]>='A'&&B[b[i]-'A']>=0){
				B[b[i]-'A']=-1;
			} 
		}
		int ans=0;
		for(int i=0;i<26;i++){
			if(B[i]==-1) ans+=A[i];
			else if(B[i]>=0){
				ans+=min(B[i],A[i]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
