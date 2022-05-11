// searching in rotated sorted array
// the array is sorted before and after the pivot(i.e min element)

// divide the array into two parts at the min elemnt
// and serch in that two parts and return the index
// https://www.youtube.com/watch?v=Id-DdcWb5AU&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=8

// LeetCode33 - https://leetcode.com/problems/search-in-rotated-sorted-array/

// Leetcode solution optimized
#include<bits/stdc++.h>
using namespace std;

int n, k;
int search(int a[], int k) {
	int s = 0;
	int e = n - 1;


	while (s <= e) {
		int mid = s + (e - s) / 2;

		if (a[mid] == k) {
			return mid;
		}
		else if (a[s] <= a[mid]) {
			if (k >= a[s] and k <= a[mid])e = mid;
			else s = mid + 1;
		}
		else if (a[s] > a[mid]) {
			if (k >= a[mid] and k <= a[e])s = mid + 1;
			else e = mid;
		}
	}
	return -1;
}
int main() {

	cin >> n;
	cin >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s = 0, e = n - 1;
	cout << search(a, k);

}