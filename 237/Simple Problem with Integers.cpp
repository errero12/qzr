#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010  //元素总个数
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define ll long long
ll read(){
    ll x = 0, f = 1;
    char c = getchar();
    for (;!isdigit(c); c= getchar()) if (c == '-') f = -1;
    for (;isdigit(c); c= getchar()) x = x * 10 + c - 48;
    return x * f;
}
ll Sum[maxn<<2],Add[maxn<<2];//Sum求和，Add为懒惰标记 
ll A[maxn],n;//存原数组数据下标[1,n] 
//PushUp函数更新节点信息 ，这里是求和
void PushUp(ll rt){Sum[rt]=Sum[rt<<1]+Sum[rt<<1|1];}
//Build函数建树 
void Build(ll l,ll r,ll rt){ //l,r表示当前节点区间，rt表示当前节点编号
	if(l==r) {//若到达叶节点 
		Sum[rt]=A[l];//储存数组值 
		return;
	}
	ll m=(l+r)>>1;
	//左右递归 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	//更新信息 
	PushUp(rt);
}
void PushDown(ll rt,ll ln,ll rn){
	//ln,rn为左子树，右子树的数字数量。 
	if(Add[rt]){
		//下推标记 
		Add[rt<<1]+=Add[rt];
		Add[rt<<1|1]+=Add[rt];
		//修改子节点的Sum使之与对应的Add相对应 
		Sum[rt<<1]+=Add[rt]*ln;
		Sum[rt<<1|1]+=Add[rt]*rn;
		//清除本节点标记 
		Add[rt]=0;
	}
}
void Update(ll L,ll R,ll C,ll l,ll r,ll rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号 
	if(L <= l && r <= R){//如果本区间完全在操作区间[L,R]以内 
		Sum[rt]+=C*(r-l+1);//更新数字和，向上保持正确
		Add[rt]+=C;//增加Add标记，表示本区间的Sum正确，子区间的Sum仍需要根据Add的值来调整
		return ; 
	}
	ll m=(l+r)>>1;
	PushDown(rt,m-l+1,r-m);//下推标记
	//这里判断左右子树跟[L,R]有无交集，有交集才递归 
	if(L <= m) Update(L,R,C,l,m,rt<<1);
	if(R >  m) Update(L,R,C,m+1,r,rt<<1|1); 
	PushUp(rt);//更新本节点信息 
} 
ll Query(ll L,ll R,ll l,ll r,ll rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号
	if(L <= l && r <= R){
		//在区间内，直接返回 
		return Sum[rt];
	}
	ll m=(l+r)>>1;
	//下推标记，否则Sum可能不正确
	PushDown(rt,m-l+1,r-m); 
	//累计答案
	ll ANS=0;
	if(L <= m) ANS+=Query(L,R,l,m,rt<<1);
	if(R >  m) ANS+=Query(L,R,m+1,r,rt<<1|1);
	return ANS;
} 
int main (){
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	ll n, q;
	cin >> n >> q;
	for(ll i = 1; i <= n; i++){
		A[i] = read();
	}
	Build(1, n, 1);
	while(q--){
		ll mm, xx, yy;
		mm = read();
		xx = read();
		yy = read();
		if(mm == 1){
			ll x; 
			x = read();
			Update(xx, yy, x, 1, n, 1);
		}
		else{
			//cout << Query(xx, yy, 1, n, 1) << endl;
			printf("%lld\n", Query(xx, yy, 1, n, 1));
		}
	}
}
