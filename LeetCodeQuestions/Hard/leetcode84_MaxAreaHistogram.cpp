// Leetcode84 - Max Area Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// https://www.youtube.com/watch?v=J2X70jj_I1o&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=7


// Accepted Solution
class Solution {
public:
	int largestRectangleArea(vector<int>& a) {

		vector<int> v1, v;
		stack<int> s, s1;

		int n = a.size();

		// Next Smaller Left
		for (int i = 0; i < n; i++) {
			if (s1.size() == 0)v1.push_back(-1);
			else if (s1.size() > 0 && a[s1.top()] < a[i])v1.push_back(s1.top());
			else if (s1.size() > 0 && a[s1.top()] >= a[i]) {
				while (s1.size() > 0 && a[s1.top()] >= a[i])s1.pop();
				if (s1.size() == 0)v1.push_back(-1);
				else v1.push_back(s1.top());
			}
			s1.push(i);
		}

		// Next Smaller Right
		for (int i = n - 1; i >= 0; i--) {
			if (s.size() == 0)v.push_back(n);
			else if (s.size() > 0 && a[s.top()] <= a[i])v.push_back(s.top());
			else if (s.size() > 0 && a[s.top()] > a[i]) {
				while (s.size() > 0 && a[s.top()] > a[i])s.pop();
				if (s.size() == 0)v.push_back(n);
				else v.push_back(s.top());
			}
			s.push(i);
		}
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < v.size(); i++) {
			v[i] = a[i] * (v[i] - v1[i] - 1);
		}
		return *max_element(v.begin(), v.end());

	}
};