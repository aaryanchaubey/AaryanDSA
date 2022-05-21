//  https://www.youtube.com/watch?v=3RhGdmoF_ac&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=15
// consider a[] = 1 3 8 10 15 & key = 12
// there are three approaches

// Approach 1
// create a vector that contains the abs(a[i] - key)
// to ur surprise it would be a rotated array
// find the index of min element in that array and return a[min element];

// Approach 2
// compare min(abs(ceil(key) - key) & abs(floor(key) - key) and return a[i having least abs() value];

// Approach 3 .. forget everything above buddy you know binary search
// just apply binary search throughtout..
// you will find that at the point when start > end .. the edge condition of ur while loop
// i.e while(start <= end) terminates
// start and end point to the neighbours of the key and thats the catch !!
// compare abs(a[start] - key) & abs(a[end] - key)) and return a[i having least abs() value];;

#include<bits/stdc++.h>
using namespace std;

int n, k;

int findMinDiffElementBS(int a[]) {
	int s = 0, e = n - 1;
	int mid = s + (e - s) / 2;
	while (s <= e) {
		if (a[mid] == k)return a[mid];
		else if (a[mid] < k)s = mid + 1;
		else e = mid - 1;
		mid = s + (e - s) / 2;
	}
	if (abs(a[s] - k) > abs(a[e] - k))return a[e];
	else return a[s];
}

int main() {

	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << findMinDiffElementBS(a);

}
