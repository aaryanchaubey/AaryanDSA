// Leetcode 540. Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/

// Accepted Solution

class Solution {
public:


	int countOffirstLast(vector<int>& a, int k) {
		int s = 0, e = a.size() - 1, res = -1;
		pair<int, int> p;
		int mid = s + (e - s) / 2;
		while (s <= e) {
			if (a[mid] == k) {
				p.first = mid;
				e = mid - 1;
			}
			else if (a[mid] < k)s = mid + 1;
			else e = mid - 1;
			mid = s + (e - s) / 2;
		}
		s = 0, e = a.size() - 1;
		while (s <= e) {
			if (a[mid] == k) {
				p.second = mid;
				s = mid + 1;
			}
			else if (a[mid] < k)s = mid + 1;
			else e = mid - 1;
			mid = s + (e - s) / 2;
		}
		return (p.second - p.first) + 1;
	}
	int singleNonDuplicate(vector<int>& a) {
		// int res = 0;
		for (int i = 0; i < a.size(); i++)if (countOffirstLast(a, a[i]) == 1)a[0] = a[i];
		return a[0];
	}
};