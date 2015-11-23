#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		vector<int> res;
		if (m == 0)
			return res;
		int n = matrix[0].size();
		if (n == 0)
			return res;
		int circle = (m > n ? n : m) / 2 + 1;
		int i, j, cnum;
		i = j = 0;
		cnum = 0;
		if (m == 1 || n == 1) {
			while (i < m) {
				j = 0;
				while (j < n) {
					res.push_back(matrix[i][j++]);
				}
				++i;
			}
			return res;
		}
		while (++cnum < circle) {
			// go left
			while (j < n - cnum) {
				res.push_back(matrix[i][j++]);
			}
			// go down
			while (i < m - cnum) {
				res.push_back(matrix[i++][j]);
			}
			// go left
			while (j > cnum - 1) {
				res.push_back(matrix[i][j--]);
			}
			//go up
			while (i > cnum - 1) {
				res.push_back(matrix[i--][j]);
			}
			//next circle
			++i, ++j;
		}
		/*if (m & 1 && m == n) {
			res.push_back(matrix[i - 1][j - 1]);
		}*/
		if (m & 1 || n & 1) {
			while (i <= m - cnum && j <= n - cnum) {
				res.push_back(matrix[i][j]);
				if (i == m - cnum)
					++j;
				else
					++i;
			}
		}
		return res;
	}
};

void test() {
	vector<vector<int>> t1 = { {1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15} };
	vector<vector<int>> t2 = { { 1,2 },{ 4,5 } };

	vector<int> res = (new Solution)->spiralOrder(t1);
	for (auto ele : res) {
		cout << ele << ' ';
	}
}