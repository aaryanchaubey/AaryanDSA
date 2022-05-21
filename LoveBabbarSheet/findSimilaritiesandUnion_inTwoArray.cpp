// find similarities b/w two arrays
// https://www.codingninjas.com/codestudio/problems/find-similarities-between-two-arrays_1229070?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

// example
// ‘ARR1’ is [1,2]
// ‘ARR2’ is [3,4]
// Elements common to ‘ARR1’ and ‘ARR2’ are []. Therefore the number of elements common to ‘arr’ and ‘brr’ is 0.
// The union of ‘ARR1’ and ‘ARR2’ is [1,2,3,4]. Therefore the number of distinct elements in the union of ‘ARR1’ and ‘ARR2’ is 4.

// Therefore the answer is 0 4.

// solution
#include<bits/stdc++.h>
using namespace std;

pair < int , int > findSimilarity(int a1[], int a2[], int n, int m)
{
	// Write Your Code here.
	pair<int, int> p;
	p.first = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a1[i] << " " << a2[j] << endl;
			if (a1[i] == a2[j])p.first += 1;
		}
	}
	p.second = m + n - p.first;
	return p;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int a1[n], a2[m];
		for (int i = 0; i < n; i++)cin >> a1[i];
		for (int i = 0; i < m; i++)cin >> a2[i];

		pair<int, int> p = findSimilarity(a1, a2, n, m);
		cout << p.first << " " << p.second << endl;
	}


}