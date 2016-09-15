#pragma once

#include "leetCodeHead.h"

class Solution {

	int min(int a, int b, int c) {
		if (a < b)
			return a < c ? a : c;
		else
			return b < c ? b : c;
	}

public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		int n = m == 0 ? 0 : matrix[0].size();

		if (m == 0 || n == 0) {
			return 0;
		}

		vector<vector<int>> dp;
		for (int i = 0; i < m; ++i) {
			vector<int> row(n, 0);
			dp.push_back(row);
		}


		int max = 0;


		//dp first row
		for (int j = 0; j < n; ++j) {
			if (matrix[0][j] == 1) {
				dp[0][j] = 1;
				max = 1;
			} else {
				dp[0][j] = 0;
			}
		}

		//dp first col
		for (int i = 0; i < m; ++i) {
			if (matrix[i][0] == 1) {
				dp[i][0] = 1;
				max = 1;
			} else {
				dp[i][0] = 0;
			}
		}

		//dp others
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[i][j] == 1) {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
					max = max > dp[i][j] ? max : dp[i][j];
				} else {
					dp[i][j] = 0;
				}
			}
		}

		return max * max;
	}
};

void test() {
	vector<vector<char>> mat= 
	{ {1,0,1,0,0},
	  {1,0,1,1,1},
	  {1,1,1,1,1},
	  {1,0,0,1,0}
	};
	Solution s;
	cout << s.maximalSquare(mat);
}