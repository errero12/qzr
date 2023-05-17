#include<cstdio>

const int maxn = 1e6 + 5;

int a[maxn], b[maxn];
/*
Nim游戏结论：
若a1⊕a2⊕a3…⊕an ≠ 0，先手必胜。
若a1⊕a2⊕a3…⊕an = 0，先手必败。
*/
int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        int sig = 0, f1 = 0, f2 = 0, f3 = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        //每堆石子ai与bi只有四种情况：1.奇/偶； 2.奇/奇； 3.偶/奇； 4.偶/偶
        for(int i = 0; i < n; i++) {
            // case 1
            if(a[i] % 2 == 1 && b[i] == 2) 
                f1 = 1;
            //case 2, 3, 4
            if(((a[i]%2 == 0 && b[i] == 2) ||
                (a[i]%2 == 0 && b[i] == 1) ||
                (a[i]%2 == 1 && b[i] == 1) ) && a[i] > 1) 
                f2++;
        }
 
        if(f1 == 1|| f2 > 1) {
            printf("Bob\n");
            continue;
        }
        else if(f1 == 0 && f2 == 0) { //四种情况都没有
            sig = 0;
            for(int i = 0; i < n; i++)
                sig ^= a[i];
            if(sig != 0)
                printf("Alice\n");
            else
                printf("Bob\n");
            continue;
        }
 
        for(int i = 0; i < n; i++) {
            if(a[i]%2 == 0 && b[i] == 2) // Alice必须把这堆取完，否则Bob就可以将其变为奇数
                a[i] = 0;
            if(a[i]%2 == 0 && b[i] == 1) // Alice必须把这堆取了只剩一个，如果剩3个以上，Bob就可以将其变为偶数
                a[i] = 1;
            if(a[i]%2 == 1 && b[i] == 1 && a[i] > 1) // Alice必须把这堆取完，否则Bob就可以将其变为偶数
                a[i] = 0;
        }
 
        for(int i = 0; i < n; i++)
            sig ^= a[i];
        if(sig == 0)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
