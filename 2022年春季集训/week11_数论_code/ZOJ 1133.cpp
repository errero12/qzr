#include <iostream>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int factDigitSum(int n) {
    int sum = 0, count = 0;
    for(int i=2; i*i<=n; i++) {
        while(n % i == 0) {
            count++;
            sum += digitSum(i);
            n /= i;
        }
    }
    if(n > 1 && count)
        sum += digitSum(n);
    if(count == 0)
        sum = -1;
 
    return sum;
}


int main() {
    int n;
    while(cin >> n && n) {
        while(++n) {
            if(digitSum(n) == factDigitSum(n)) {
                cout << n << endl;
                break;
            }
        }
    }
    return 0;
}