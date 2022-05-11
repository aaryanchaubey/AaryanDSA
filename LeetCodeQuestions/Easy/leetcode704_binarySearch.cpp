// Leetcode 704 - easy - binary search
// https://leetcode.com/problems/binary-search/
// https://www.youtube.com/watch?v=gY2b-Q6wDEM&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=4

// Accepted Solution
class Solution {
public:
	int search(vector<int>& a, int k) {

		int s = 0, e = a.size() - 1;
		int mid = s + (e - s) / 2;
		while (s <= e) {
			if (a[mid] == k)return mid;
			else if (a[mid] < k)s = mid + 1;
			else e = mid - 1;
			mid = s + (e - s) / 2;
		}

		return -1;
	}
};
