#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& v, int k) {
	int s = 0, e = v.size() - 1;
	vector<int> a;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		// cout << mid << " mid" << endl;
		if (v[mid] == k) {
			// cout << mid << endl;
			a.push_back(mid);
			return a;
		}
		else if (v[mid] > k) {

			if (s != 0) {
				// cout << mid << " mid" << endl;
				e = s - 1;
				// cout << e << " e" << endl;
				s = 0;
			}
			else {
				// cout << mid << endl;
				e = mid - 1;
				s = 0;
			}
		}
		else if (v[mid] < k) {
			cout << mid << endl;
			s = mid + 1;
			a.push_back(s);
			k = k - v[mid];
			// cout << k << endl;;
		}

	}
	return a;
}

int maxProfit(vector<int> prices) {
	int n = prices.size();
	int maxRight[n];

	maxRight[n - 1] = prices[n - 1];
	// cout << maxRight[n - 1] << " ";
	for (int i = n - 2; i >= 0; i--) {

		// cout << maxRight[i + 1] << " " << prices[i] << endl;
		maxRight[i] = max(maxRight[i + 1], prices[i]);
		// cout << maxRight[i] << " ";
	}
	// cout << endl;
	for (int i = 0; i < n; i++) {
		maxRight[i] = maxRight[i] - prices[i];
		// cout << maxRight[i] << " ";
	}
	// cout << endl;
	return *max_element(maxRight , maxRight + n);;
}


vector<int> plusOne(vector<int>& digits) {
	int n = digits.size();
	int s = digits[n - 1];
	digits.pop_back();
	int c = 0;
	while ((s + 1) % 10 == 0 && digits.size() > 0) {
		int s = digits[n - 1];
		if (digits[n - 1] + 1 % 10 == 0) {
			c++;
			digits.pop_back();
		}
	}
	cout << c << " ";
	// if (n == 0) {

	// }
	digits.push_back((s + 1) % 10);
	return digits;
}
int main() {
	int n, a, k;
	cin >> n;// >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	v = plusOne(v);
	for (auto x : v) {
		// cout << x << " ";
	}
	// vector<int> z = twoSum(v, k);
	// sort(z.begin(), z.end());
	// for (auto x : z) {
	// 	cout << x << " ";
	// }

	// int n, a;
	// cin >> n;
	// vector<int> v;
	// for (int i = 0; i < n; i++) {
	// 	cin >> a;
	// 	v.push_back(a);
	// }
	// cout << maxProfit(v);

}