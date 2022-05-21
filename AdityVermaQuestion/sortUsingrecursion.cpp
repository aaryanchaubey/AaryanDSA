// https://www.youtube.com/watch?v=AZ4jEY_JAVc&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=6
// https://practice.geeksforgeeks.org/problems/sort-a-stack/1

#include<bits/stdc++.h>
using namespace std;

// GFG sort stack Accepted solution
// void SortedStack :: sort()
// {
//    //Your code here
//    if (s.size() == 1)return;
// 	int val = s.top();
// 	s.pop();
// 	sort();
// 	insert(s, val);
// insert function below this code

// }

// sorting an array
// void insert(vector<int>& v, int temp) {

// 	if (v.size() == 0 or v[v.size() - 1] <= temp) {
// 		v.push_back(temp);
// 		return;
// 	}
// 	int val = v[v.size() - 1];
// 	v.pop_back();
// 	insert(v, temp);
// 	v.push_back(val);
// }

// void sortR(vector<int>& v) {

// 	if (v.size() == 1)return;
// 	int val = v[v.size() - 1];
// 	v.pop_back();
// 	sortR(v);
// 	insert(v, val);

// }


// sorting a stack
void insert(stack<int>& v, int temp) {

	if (v.size() == 0 or v.top() <= temp) {
		v.push(temp);
		return;
	}
	int val = v.top();
	v.pop();
	insert(v, temp);
	v.push(val);
}

void sortR(stack<int>& v) {

	if (v.size() == 1)return;
	int val = v.top();
	v.pop();
	sortR(v);
	insert(v, val);
}


int main() {
	int n;
	cin >> n;
	int temp;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		s.push(temp);
	}

	cout << endl;
	sortR(s);
	while (s.size() != 0) {
		cout << s.top() << " ";
		s.pop();
	}

}