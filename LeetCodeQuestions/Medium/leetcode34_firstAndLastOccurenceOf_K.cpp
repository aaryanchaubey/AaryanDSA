//  LeetCode Medium  34
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
// // https://www.youtube.com/watch?v=zr_AoTxzn0Y&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=5

// Accepted Solution - using binary search
class Solution {
public:

	int first(vector<int>& a, int k) {
		int s = 0 , e = a.size() - 1, res = -1;
		int mid = s + (e - s) / 2;

		// first occurence
		while (s <= e) {
			if (a[mid] == k) {
				res = mid;
				e = mid - 1; // eliminating the occurence till we get the first
			}
			else if (a[mid] < k) {
				s = mid + 1;
			}
			else e = mid - 1;
			mid = s + (e - s) / 2;
		}
		return res;
	}
	int last(vector<int>& a, int k) {
		int s = 0 , e = a.size() - 1, res = -1;
		int mid = s + (e - s) / 2;

		// last occurence
		while (s <= e) {
			if (a[mid] == k) {
				res = mid;
				s = mid + 1; // eliminating the occurence till we get the first
			}
			else if (a[mid] < k) {
				s = mid + 1;
			}
			else e = mid - 1;
			mid = s + (e - s) / 2;
		}
		return res;

	}
	vector<int> searchRange(vector<int>& n, int k) {

		vector<int> b;
		b.push_back(first(n, k));
		b.push_back(last(n, k));
		return b;
	}
};



