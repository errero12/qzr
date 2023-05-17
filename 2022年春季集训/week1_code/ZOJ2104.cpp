#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	int n;
	while(cin >> n && n) {
		map<string, int> ball;
		string s;
		while(n--) {
			cin >> s;
			ball[s]++;
		}
		int max = 0;
		map<string, int>::iterator p, maxP;
		for(p = ball.begin(); p != ball.end(); p++) {
			if (p -> second > max) {
				max = p -> second;
				maxP = p;
			}
		}
		cout << maxP -> first << endl;
	}
	return 0;
}