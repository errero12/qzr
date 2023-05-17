#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    printf("在下方输入要进行排序的数（crtl+c结束）：\n");
    int cnt = 0;
    while(scanf("%d", &a[cnt++])!=EOF){
        ;
    }
    for(int i = 1; i < cnt; ++i){
        for(int j = i-1; j >= 0; --j){
            if(a[j+1]>a[j]){
                swap(a[j+1], a[j]);
            }
            else{
                break;
            }
        }
    }
    for(int i = 0; i < cnt; ++i){
        printf("%d ", a[i]);
    }
    puts("");
    system("pause");
}