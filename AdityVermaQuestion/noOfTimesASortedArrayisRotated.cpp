// no of times a sorted array is rotated
// https://www.youtube.com/watch?v=4WmTRFZilj8&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=7

//  Leetcode - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// brute force - if aim is to only return the min element
// sort the array and return first element ..

// if aim is to return the index or to return the min element without sorting
// when array is rotated by keeping front elements back
// Approach - we find min element and we return n - index of min element

// i know its one and the same but its a matter of persepective

// when array is rotated by keeping back elements front
// Approach - we find min element and we return index of min element

// Solution
#include<bits/stdc++.h>
using namespace std;
int n;

// Leetcode Solution - 1
int minElement(int nums[]) {
	sort(nums, nums + n);
	return nums[0];
}

// Leed code Solution - 2 .. return a[mid]
int noOfRotations(int a[]) {

	int s = 0 , e = n - 1;
	int mid = s + (e - s) / 2;
	int prev = (n + mid - 1) % n, next = (mid + 1) % n;
	while (s <= e) {

		if (a[e] > a[s])return -1;
		else if (a[mid] <= a[prev] && a[mid] <= a[next]) {
			return mid;
		}

		else if (a[s] < a[mid]) {
			if (mid % 2 == 0)s = mid;
			else s = mid + 1;
		}
		else if (a[mid] < a[e]) {
			e = mid - 1;
		}
		// else return n - e;
		mid = s + (e - s) / 2;
	}
}

int main() {

	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << noOfRotations(a);
}
