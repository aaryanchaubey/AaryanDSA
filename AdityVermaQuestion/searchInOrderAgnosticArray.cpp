// https://www.youtube.com/watch?v=gY2b-Q6wDEM&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=4
// it is an array where we do not know the type of sorting
// it may be ascending or descending
// if a[0] < a[n-1] - ascending else descending

// tstcase -
// 6
// 8
// 1 3 5 8 9 10 or 10 8 7 6 5 4

#include<bits/stdc++.h>
using namespace std;

int n, k;

int binarySearch(int a[]) {

	int s = 0, e = n - 1;
	int mid = s + (e - s) / 2;

	while (s <= e) {
		if (a[mid] == k)return mid;
		else if (a[0] < a[n - 1]) {
			if (a[mid] < k)s = mid + 1;
			else e = mid - 1;
		}
		else {
			if (a[mid] < k)e = mid - 1;
			else s = mid + 1;
		}
		mid = s + (e - s) / 2;
	}
	return -1;
}

int main() {

	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << binarySearch(a);
}