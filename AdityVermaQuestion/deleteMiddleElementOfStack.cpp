// https://www.youtube.com/watch?v=oCcUNRMl7dA&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=8
// GFG - Solution below
// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1/


#include<bits/stdc++.h>
using namespace std;

void deletemid(stack<int>& s, int k) {

	// base condn
	if (s.size() == 0)return;
	if (k == 1) {
		s.pop();
		return;
	}

	// hypothesis
	int val = s.top();
	s.pop();
	deletemid(s, k - 1);

	s.push(val); // induction
}

int main() {
	int n, tmp;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		s.push(tmp);
	}

	deletemid(s, (n + 1) / 2);
	while (s.size() != 0) {
		cout << s.top() << " ";
		s.pop();
	}
}

// GFG Accepted Solution
// class Solution
// {
//     public:
//     //Function to delete middle element of a stack.
//     void deleteMid(stack<int>&s, int size)
//     {
// 		if (s.size() == 0)return;
//      if(s.size() == 1){
//          s.pop();
//          return;
//         }
//         int val = s.top();
//         s.pop();
//         deleteMid(s,n-1);
//         s.push(val);
//     }
// };