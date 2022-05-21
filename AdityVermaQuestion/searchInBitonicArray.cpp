#include<bits/stdc++.h>
using namespace std;

int k, x;
vector<int> v;
int binarySearch(int s, int e) {
	while (s <= e) {

		int mid = s + (e - s) / 2;
		if (v[mid] == k)return mid;
		else if (v[mid] > k)e = mid - 1;
		else s = mid + 1;
	}
	return -1;
}
int binarySearch2(int s, int e) {
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (v[mid] == k)return mid;
		else if (v[mid] > k)s = mid + 1;
		else e = mid - 1;
	}
	return -1;
}

int maxElementBitonicArray(vector<int> a) {
	int n = a.size();
	int s = 0, e = n - 1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (mid > 0 && mid < n - 1) {
			if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1])return mid;
			else if (a[mid + 1] > a[mid - 1])s = mid + 1;
			else if (a[mid + 1] < a[mid - 1])e = mid - 1;
		}
		else if (mid == 0) {
			if (a[0] > a[1])return 0;
			else return 1;
		}
		else if (mid == n - 1) {
			if (a[n - 1] > a[n - 2])return n - 1;
			else return n - 2;
		}
	}
}

int main() {

	int n, a;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	x = maxElementBitonicArray(v);
	// cout << x << endl;
	int s1 = binarySearch(0, x);
	int s2 = binarySearch2(x + 1, n - 1);
	if (s1 != -1)cout << s1 << endl;
	else cout << s2 << endl;
}