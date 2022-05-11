// first and last occurence of an element in array

// Leetcode - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// https://www.youtube.com/watch?v=zr_AoTxzn0Y&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=5
// test case
// 8
// 4
// 1 2 4 4 4 4 4 8

#include<bits/stdc++.h>
using namespace std;

int n, k;

// finding total occurences
int firstLast(int a[]) {

// uncomment for finding fist and last
// pair<int,int> firstLast(int a[]) {
	int s = 0 , e = n - 1;
	pair<int, int> p;
	int mid = s + (e - s) / 2;

	// first occurence
	while (s <= e) {
		if (a[mid] == k) {
			p.first = mid;
			e = mid - 1; // eliminating the occurence till we get the first
		}
		else if (a[mid] < k) {
			s = mid + 1;
		}
		else e = mid - 1;
		mid = s + (e - s) / 2;
	}

	s = 0 , e = n - 1;

	// last occurence
	while (s <= e) {
		if (a[mid] == k) {
			p.second = mid;
			s = mid + 1; // eliminating the occurence till we get the last
		}
		else if (a[mid] < k) {
			s = mid + 1;
		}
		else e = mid - 1;
		mid = s + (e - s) / 2;
	}

	// return p;
	//  for finding total occurences
	return (p.second - p.first + 1);
}
int main() {
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// pair<int, int> p = firstLast(a);
	// cout << p.first << " " << p.second;

	// for finding total occurence
	cout << firstLast(a);
}