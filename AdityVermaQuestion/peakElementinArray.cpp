// https://www.youtube.com/watch?v=OINnBJTRrMU&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=17

#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<int> v) {
	int s = 0 , e = v.size() - 1;

	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (mid > 0 && mid < v.size() - 1 ) {
			if ( v[mid - 1] < v[mid] && v[mid] > v[mid + 1])return mid;
			else if (v[mid - 1] < v[mid + 1])s = mid + 1;
			else if (v[mid - 1] > v[mid + 1])e = mid - 1;
		}
		else if (mid == 0) {
			if (v[0] > v[1])return 0;
			else return 1;
		}
		else if (mid == v.size() - 1) {
			if (v[v.size() - 1] > v[v.size() - 2])return v.size() - 1;
			else v.size() - 2;
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
	cout << peakElement(v);
}