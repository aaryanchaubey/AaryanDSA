// https://www.youtube.com/watch?v=BrrZL1RDMwc&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=18

#include<bits/stdc++.h>
using namespace std;

int maxElementBitonic(vector<int> v) {
	int n = v.size();
	int s = 0, e = n - 1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (mid > 0 && mid < n - 1) {
			if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1])return mid;
			else if (v[mid + 1] < v[mid - 1])e = mid - 1;
			else if (v[mid + 1] > v[mid - 1])s = mid + 1;
		}
		else if (mid == 0) {
			if (v[0] > v[1])return 0;
			else return 1;
		}
		else if (mid == n - 1) {
			if (v[n - 1] > v[n - 2])return n - 1;
			else return n - 2;
		}
	}
	return -1;
}

int main() {
	int n, a;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	cout << maxElementBitonic(v);
}