// https://leetcode.com/problems/single-number/
// https://www.youtube.com/watch?v=1LyAr7sgkZQ&list=PLKZaSt2df1gwgL9IH2rH9l9HcXbNx16hx&index=4
// https://www.youtube.com/watch?v=7VoJn544QrM&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=6

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int k;


vector<pi> kthMostFrequent(vector<int> v) {
	unordered_map<int, int> mp;
	for (int i = 0; i < v.size(); i++) {
		mp[v[i]]++;
	}
	priority_queue<pi> minheap;
	for (auto i = mp.begin(); i != mp.end(); i++) {
		minheap.push(make_pair(i->second, i->first));
		if (minheap.size() > k)minheap.pop();
	}
	vector<pi> z;
	while (minheap.empty() == false)
	{
		z.push_back(minheap.top());// << " - " << z.second.push_back(minheap.top().first) << endl;
		minheap.pop();
	}
	return z;

}

int main() {
	int n, a;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	vector<pi> z = kthMostFrequent(v);
	for (auto x : z) {
		cout << x.second << " - " << x.first << endl;
	}

}

