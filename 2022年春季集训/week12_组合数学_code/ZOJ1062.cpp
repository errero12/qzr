#include <iostream>
using namespace std;
int c[20], s[20];

void init () {
    c[0] = c[1] = 1;
    s[0] = 0, s[1] = 1;
    for (int i = 2; i <= 19; i++) {
        int catalan = 0;
        int k = i - 1;
        for (int j = 0; j < i; j++, k--)
            catalan += c[j] * c[k];
        c[i] = catalan;
        s[i] = s[i - 1] + catalan;
    }
}

void outPutTree(int n, int x) {
    if (n == 0)
        return;
    if (n == 1) {
        cout << "X";
        return;
    }
    int i, j, left;
    j = n - 1;

    for (i = 0; i < n; i++, j--) {
        left = c[i] * c[j];
        if (x > left)
            x -= left;
        else
            break;
    }
    x -= 1;

    if (i != 0) {
        cout << "(";
        outPutTree(i, x / c[j] + 1);
        cout << ")";
    }
    cout << "X";
    if (j != 0) {
        cout << "(";
        outPutTree(j, x % c[j] + 1);
        cout << ")";
    }
}

int main() {
    init();
    int n;
    while(cin >> n && n) {
        int i;
        for (i = 1; i <= 19; ++ i)
            if (n <= s[i])
                break;
        outPutTree(i, n - s[i - 1]);
        cout << endl;
    }
    return 0;
}