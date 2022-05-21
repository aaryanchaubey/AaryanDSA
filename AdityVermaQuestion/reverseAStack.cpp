// https://www.youtube.com/watch?v=8YXQ68oHjAs&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=9

#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>& s, int tmp) {
	if (s.size() == 0) {
		s.push(tmp);
		return;
	}
	int val = s.top();
	s.pop();
	insert(s, tmp);
	s.push(val);
}
void reverseS(stack<int>& s) {
	if (s.size() == 1)return;
	int val = s.top();
	s.pop();
	reverseS(s);
	insert(s, val);
	return;
}

int main() {
	int n;
	cin >> n;
	stack<int> s;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.push(a);
	}
	reverseS(s);
	while (s.size() != 0) {
		cout << s.top() << " ";
		s.pop();
	}

}