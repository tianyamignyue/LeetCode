#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix;
		if (n <= 0)
			return matrix;
		for (int i = 0; i < n; ++i) {
			vector<int> row(n);
			matrix.push_back(row);
		}
		int circle = n / 2;
		int ele = 1;
		int i, j, cnum;
		i = j = 0;
		cnum = 0;
		while (++cnum <= circle) {
			// go left
			while (j < n - cnum) {
				matrix[i][j++] = ele++;
			}
			// go down
			while (i < n - cnum) {
				matrix[i++][j] = ele++;
			}
			// go left
			while (j > cnum - 1) {
				matrix[i][j--] = ele++;
			}
			//go up
			while (i > cnum - 1) {
				matrix[i--][j] = ele++;
			}
			//next circle
			++i, ++j;
		}
		if (n & 1) {
			matrix[i][j] = ele;
		}
		return matrix;
	}
};

void test() {
	vector<vector<int>> res = (new Solution)->generateMatrix(3);
	for (auto row : res) {
		for (auto ele : row) {
			cout << ele << " ";
		}
		cout << endl;
	}
}