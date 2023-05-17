#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	set<string> s;
	string str, str1, str2;
	s.clear();
	while(cin >> str) {
		s.insert(str);
	}
	for (set<string>::iterator p = s.begin(); p != s.end(); p++) {
		str = *p;
		int len = str.length();
		for (int i = 1; i < len; i++) {
			str1 = str.substr(0, i);
			str2 = str.substr(i, len - i);
			if (s.find(str1) != s.end() && s.find(str2) != s.end()) {
				cout << str << endl;
				break;
			}
		}
	}
	return 0;
}