#include<bits/stdc++.h>
using namespace std;
int a[1011];
int temp[1011];
void gsort(int l, int r){
    if(l>=r){
        return;
    }
    int mid = (l+r)/2;
    gsort(l, mid);
    gsort(mid+1, r);
    int key1 = l;
    int key2 = mid+1;
    int ct = l;
    while(key1 <= mid&&key2 <= r){
        if(a[key1]>a[key2]){
            temp[ct++]=a[key1];
            key1++;
        }
        else{
            temp[ct++]=a[key2];
            key2++;
        }
    }
    while(key1 <= mid){
        temp[ct++]=a[key1];
            key1++;
    }
    while(key2 <= r){
        temp[ct++]=a[key2];
            key2++;
    }
    for(int i = l; i <= r; ++i){
        a[i]=temp[i];
    }
    return;
}
int main(){
    printf("输入排序的数字个数：\n");
    int n;
    scanf("%d", &n);
    printf("在下方输入要排序的数：\n");
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    gsort(1, n);
    for(int i = 1; i <= n; ++i){
        printf("%d ", a[i]);
    }
    system("pause");
}