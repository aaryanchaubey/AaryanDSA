// https://leetcode.com/problems/binary-search/

// testcase format
// 6
// 3
// 1 3 5 8 9 10

// brute force - linear search

#include<bits/stdc++.h>
using namespace std;

int n;
int binarySearch(int a[], int k) {
	int start = 0;
	int end = n - 1;
	// int mid = (start+end)/2;
	int mid = start + (end - start) / 2;

	while (start <= end) {
		if (k == a[mid])return mid;
		else if (k > a[mid])start = mid + 1;
		else end = mid - 1;
		mid = start + (end - start) / 2;
	}

	return -1;
}

int main() {

	cin >> n;
	int a[n];
	int k;
	cin >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl << binarySearch(a, k);
}