#include<bits/stdc++.h>
using namespace std;
struct node{
	string s;
	int step;
	node(int _step, string _s) :
		s(_s), step(_step) {}
};
pair<string,string> pp[10];
string A, B;
int i;
int find_(string a, string b,int k1){
	int k2 = 0; 
	int l1 = a.size(), l2 = b.size();
	while(k1 < l1){//cout << k1<<"aaaa\n";
		if(a[k1] == b[k2]){
			k1++;
			k2++;
			if(k2 == l2){
				//a = a.substr()
				
				return k1 - l2;
			}
		}
		else if(k2 != 0){
			k2=0;
		}
		else k1++;
	}
	return -1;
}
map <string,int> st, _st;
int bfs(){
	//struct node a = {A, 0};
	queue<struct node> q;
	queue<struct node> _q;
	q.push(node(0,A));
	_q.push(node(0,B));
	st[A] = 0;
	_st[B] = 0;
	while(q.size()&&_q.size()){
		int step = q.front().step;
		string cur = q.front().s;
		q.pop();
		int _step = _q.front().step;
		string _cur = _q.front().s;
		_q.pop();
		if(step + _step > 10) return -1;
		for(int j = 0; j < i; j++){
			int ak = find_(cur, pp[j].first, 0);
			int len = pp[j].first.length();
			while(ak!=-1){
				string neww = cur.substr(0, ak) + pp[j].second + cur.substr(ak+len);
				if(_st.count(neww))return step + 1 + _st[neww];
				q.push(node(step + 1, neww));
				st[neww] = step + 1;
				ak = find_(cur, pp[j].first, ak + 1);
			}
			ak = find_(_cur, pp[j].second, 0);
			len = pp[j].second.length();
			while(ak!=-1){
				string neww = _cur.substr(0, ak) + pp[j].first + _cur.substr(ak+len);
				if(st.count(neww))return _step + 1 + st[neww];
				_q.push(node(_step + 1, neww));
				_st[neww] = _step + 1;
				ak = find_(_cur, pp[j].second, ak + 1);
			}
		}
	}
	return -1;
}
int main (){
	//char A[30], B[30];
	//scanf("%s%s", A, B);
	cin >> A >> B;
	i = 0;
	string aa, bb;
	while(cin >> aa >> bb){
		pp[i].first = aa;
		pp[i].second = bb;
		i++;
		//cout << pp[i].second  << " " << pp[i].first<< endl;i++;
	}
	//cout << "asddas\n";
	//for(int j = 0; j < i; j++)
	//{
		//cout << pp[i].second  << " " << pp[i].first<< endl;
	//}
	int ans = bfs();
	if(ans == -1)cout << "NO ANSWER!\n";
	else cout << ans << endl;
} 
