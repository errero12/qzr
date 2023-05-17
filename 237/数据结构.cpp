#include<bits/stdc++.h>
using namespace std;
#define maxn 1000100  //元素总个数
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define int long long
int Sum[maxn<<2],Add[maxn<<2];//Sum求和，Add为懒惰标记 
int Sum_[maxn<<2];
int A[maxn],n;
int B[maxn<<2];
int B_[maxn<<2];
int Add_[maxn<<2];
//存原数组数据下标[1,n] 
//PushUp函数更新节点信息 ，这里是求和
void PushUp(int rt){Sum[rt]=(Sum[rt<<1]+Sum[rt<<1|1]);}
void PushUp_(int rt){Sum_[rt]=(Sum_[rt<<1]+Sum_[rt<<1|1]);}
//Build函数建树 
void Build(int l,int r,int rt){ //l,r表示当前节点区间，rt表示当前节点编号
	if(l==r) {//若到达叶节点 
		Sum[rt]=A[l];//储存数组值 
		return;
	}
	int m=(l+r)>>1;
	//左右递归 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	//更新信息 
	PushUp(rt);
}

void Build_(int l,int r,int rt){ //l,r表示当前节点区间，rt表示当前节点编号
	if(l==r) {//若到达叶节点 
		Sum_[rt]=A[l]*A[l];//储存数组值 
		return;
	}
	int m=(l+r)>>1;
	//左右递归 
	Build_(l,m,rt<<1);
	Build_(m+1,r,rt<<1|1);
	//更新信息 
	PushUp_(rt);
}
void PushDown_(int rt,int ln,int rn){
	//ln,rn为左子树，右子树的数字数量。
		//下推标记 
		Add[rt<<1] = (Add[rt] + B[rt]*Add[rt<<1]);
		Add[rt<<1|1] = (Add[rt] + B[rt]*Add[rt<<1|1]);
		B[rt<<1] = (B[rt<<1] * B[rt]);
		B[rt<<1|1]=(B[rt<<1|1] * B[rt]);
		Add_[rt<<1] = (Add[rt] + B[rt]*Add[rt<<1])*(Add[rt] + B[rt]*Add[rt<<1] + 2*B_[rt<<1] * B_[rt]);
		Add_[rt<<1|1] = (Add[rt] + B[rt]*Add[rt<<1|1])*(Add[rt] + B[rt]*Add[rt<<1|1] + 2*B_[rt<<1|1] * B_[rt]);
		B_[rt<<1] = (B_[rt<<1] * B_[rt])*(B_[rt<<1] * B_[rt]);
		B_[rt<<1|1]=(B_[rt<<1|1] * B_[rt])*(B_[rt<<1|1] * B_[rt]);
		Sum[rt<<1] = (Sum[rt<<1]*B[rt] + Add[rt]*ln);
		Sum[rt<<1|1] = (Sum[rt<<1|1]*B[rt] + Add[rt]*rn);
		Sum_[rt<<1] = (Sum_[rt<<1]*B_[rt]*B_[rt] + (2*Add_[rt]*B_[rt] + Add_[rt]*Add_[rt])*ln);
		Sum_[rt<<1|1] = (Sum_[rt<<1|1]*B_[rt]*B_[rt] + (2*Add_[rt]*B_[rt] + Add_[rt]*Add_[rt])*rn);
		B[rt]=1;
		Add[rt]=0;
		B_[rt]=1;
		Add_[rt]=0;
}
void Update_(int L,int R,int C,int l,int r,int rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号 
	if(L <= l && r <= R){ 
		Sum[rt]*=C;
		Sum_[rt]=(C*C)*(Sum_[rt]-2*)
		B[rt]*=C;
		B_[rt]*=C;
		Add[rt]*=C;
		Add_[rt]*=C;
		return ; 
	}
	int m=(l+r)>>1;
	PushDown_(rt,m-l+1,r-m);
	if(L <= m) Update_(L,R,C,l,m,rt<<1);
	if(R >  m) Update_(L,R,C,m+1,r,rt<<1|1); 
	PushUp(rt);
}
void Update(int L,int R,int C,int l,int r,int rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号 
	if(L <= l && r <= R){
		Sum[rt]+=C*(r-l+1);
		Sum_[rt]+=(2*Sum[rt]*C+C*C);
		Add[rt]+=C;
		Add_[rt]+=C;
		return ; 
	}
	int m=(l+r)>>1;
	PushDown_(rt,m-l+1,r-m);//下推标记
	//这里判断左右子树跟[L,R]有无交集，有交集才递归 
	if(L <= m) Update(L,R,C,l,m,rt<<1);
	if(R >  m) Update(L,R,C,m+1,r,rt<<1|1); 
	PushUp(rt);//更新本节点信息 
} 
int Query(int L,int R,int l,int r,int rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号
	if(L <= l && r <= R){
		//在区间内，直接返回 
		return Sum[rt];
	}
	int m=(l+r)>>1;
	//下推标记，否则Sum可能不正确
	PushDown_(rt,m-l+1,r-m); 
	//PushDown(rt,m-l+1,r-m);
	//累计答案
	int ANS=0;
	if(L <= m) ANS+=Query(L,R,l,m,rt<<1);
	if(R >  m) ANS+=Query(L,R,m+1,r,rt<<1|1);
	return ANS;
} 
int Query_(int L,int R,int l,int r,int rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号
	if(L <= l && r <= R){
		//在区间内，直接返回 
		return Sum_[rt];
	}
	int m=(l+r)>>1;
	//下推标记，否则Sum可能不正确
	PushDown_(rt,m-l+1,r-m); 
	//PushDown(rt,m-l+1,r-m);
	//累计答案
	int ANS=0;
	if(L <= m) ANS+=Query_(L,R,l,m,rt<<1);
	if(R >  m) ANS+=Query_(L,R,m+1,r,rt<<1|1);
	return ANS;
} 
signed main (){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	for(int i = 1; i <= n<<2; i++){
		B[i]=1;
	}
	//cout << pp << endl;
	//cout << p << endl;
	Build(1, n, 1);
	Build_(1, n, 1);
	//for(int i = 1; i <= n<<2; i++)cout << Sum[i] << endl;
	//cout << "sasdasd\n";
	for(int i = 1; i <= n<<2; i++)cout << Sum_[i] << endl;
	while(q--){
		int mm, xx, yy;
		cin >> mm >> xx >> yy;
		if(mm == 3){
			int x; 
			cin >> x;
			Update_(xx, yy, x, 1, n, 1);
		}
		else if(mm == 4)
		{
			int k;
			cin >> k;
			Update(xx, yy, k, 1, n, 1);
		}
		else if(mm == 1){
			cout << Query(xx, yy, 1, n, 1) << endl;
		}
		else{
			cout << Query_(xx, yy, 1, n, 1) << endl;
		}
	}
	for(int i = 1; i <= n<<2; i++)cout << Sum_[i] << endl;
}
