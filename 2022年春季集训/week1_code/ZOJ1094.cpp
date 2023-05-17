#include<iostream>
#include<cstring>
#include<stack>
#include<map>
using namespace std;

struct Node {
	int row, col;
};

map<char, Node> matrix;

int main() {
	int n;
	char name;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name;
		cin >> matrix[name].row >> matrix[name].col;
	}
	string exp;
	while(cin >> exp) {
		int count = 0;
		stack<Node> sk;
		unsigned i;
		for (i = 0; i < exp.size(); i++) {
			if (exp[i] == '(')
				continue;
			if (exp[i] == ')') {
				Node b = sk.top();
				sk.pop();
				Node a = sk.top();
				sk.pop();
				if (a.col != b.row) {
					cout << "error" << endl;
					break;
				}
				count += a.row * b.row * b.col;
				Node t = {a.row, b.col};
				sk.push(t);
			} else {
				sk.push(matrix[exp[i]]);
			}
		}
		if (i == exp.size()) {
			cout << count << endl;
		}
	}
	return 0;
}