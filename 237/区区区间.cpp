#include<bits/stdc++.h>
using namespace std;
#define maxn 200010  //Ԫ���ܸ���
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define int long long
int Sum[maxn<<2],Add[maxn<<2];//Sum��ͣ�AddΪ������ 
int A[maxn],n;//��ԭ���������±�[1,n] 
//PushUp�������½ڵ���Ϣ �����������
void PushUp(int rt){Sum[rt]=Sum[rt<<1]+Sum[rt<<1|1];}
void Build(int l,int r,int rt){ //l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(l==r) {//������Ҷ�ڵ� 
		Sum[rt]=A[l];//��������ֵ 
		return;
	}
	int m=(l+r)>>1;
	//���ҵݹ� 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	//������Ϣ 
	PushUp(rt);
}
void PushDown(int L, int R, int rt,int l,int r){ 
	if(Add[rt]){
		//���Ʊ�� 
		Add[rt<<1]=Add[rt];
		Add[rt<<1|1]=Add[rt];
		int m = (l+r)>>1;
		//�޸��ӽڵ��Sumʹ֮���Ӧ��Add���Ӧ 
		Sum[rt<<1]=(Add[rt]+l-L + Add[rt]+m-L)*(m-l+1)/(1ll*2);
		Sum[rt<<1|1]=(Add[rt]+m+1-L + Add[rt]+r-L)*(r-m)/(1ll*2);
		//������ڵ��� 
		Add[rt]=0;
	}
}
void Update(int L,int R,int C,int l,int r,int rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ��� 
	if(L <= l && r <= R){//�����������ȫ�ڲ�������[L,R]���� 
		Add[rt] = C;
		Sum[rt] = (C+l-L + C+r-L)*(r-l+1)/(1ll*2);//�������ֺͣ����ϱ�����ȷ
		//����Add��ǣ���ʾ�������Sum��ȷ���������Sum����Ҫ����Add��ֵ������
		return ; 
	}
	int m=(l+r)>>1;
	PushDown(L, R,l,r,rt);//���Ʊ��
	//�����ж�����������[L,R]���޽������н����ŵݹ� 
	if(L <= m) Update(L,R,C,l,m,rt<<1);
	if(R >  m) Update(L,R,C,m+1,r,rt<<1|1); 
	PushUp(rt);//���±��ڵ���Ϣ 
} 
int Query(int L,int R,int l,int r,int rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(L <= l && r <= R){
		//�������ڣ�ֱ�ӷ��� 
		return Sum[rt];
	}
	int m=(l+r)>>1;
	//���Ʊ�ǣ�����Sum���ܲ���ȷ
	PushDown(L, R,l,r,rt); 
	
	//�ۼƴ�
	int ANS=0;
	if(L <= m) ANS+=Query(L,R,l,m,rt<<1);
	if(R >  m) ANS+=Query(L,R,m+1,r,rt<<1|1);
	return ANS;
} 
signed main (){
	int m;
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++)scanf("%lld", &A[i]);
	Build(1, n, 1);//cout<<"asda\n";
	while(m--){
		int mm, l, r, k;
		scanf("%lld%lld%lld", &mm, &l, &r);
		if(mm == 1){
			scanf("%lld", &k);
			Update(l, r, k, 1, n, 1);
		}
		else{
			
			printf("%lld\n", Query(l, r, 1, n, 1));
		}
	}
}
