// Leetcode 540. Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/

// My practice Solution
#include<bits/stdc++.h>
using namespace std;

int n;
int countOffirstLast(int a[], int k) {
	int s = 0, e = n - 1, res = -1;
	pair<int, int> p;
	int mid = s + (e - s) / 2;
	while (s <= e) {
		if (a[mid] == k) {
			p.first = mid;
			e = mid - 1;
		}
		else if (a[mid] < k)s = mid + 1;
		else e = mid - 1;
		mid = s + (e - s) / 2;
	}
	s = 0, e = n - 1;
	while (s <= e) {
		if (a[mid] == k) {
			p.second = mid;
			s = mid + 1;
		}
		else if (a[mid] < k)s = mid + 1;
		else e = mid - 1;
		mid = s + (e - s) / 2;
	}
	return (p.second - p.first) + 1;
}
int main() {

	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (countOffirstLast(a, a[i]) == 1)cout << a[i];
	}
}