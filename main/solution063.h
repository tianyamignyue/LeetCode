#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		if (m == 0)
			return 0;
		int n = obstacleGrid[0].size();
		vector<vector<int>> path;
		for (int i = m - 1; i >= 0; --i) {
			vector<int> row(n, 0);
			path.push_back(row);
		}
		//last row
		int i = m - 1;
		int j = n - 1;
		//last one
		if (obstacleGrid[i][j] == 1) {
			path[i][j--] = 0;
		}
		else {
			path[i][j--] = 1;
		}
		while (j >= 0) {
			if (obstacleGrid[i][j] == 1) {
				path[i][j] = 0;
			}
			else {
				path[i][j] = path[i][j + 1];
			}
			--j;
		}
		for (i = m - 2; i >= 0; --i) {
			//last one in a row
			if (obstacleGrid[i][n - 1] == 1) {
				path[i][n - 1] = 0;
			}
			else {
				path[i][n - 1] = path[i + 1][n - 1];
			}
			for (j = n - 2; j >= 0; --j) {
				if (obstacleGrid[i][j] == 1) {
					path[i][j] = 0;
				}
				else {
					path[i][j] = path[i][j + 1] + path[i + 1][j];
				}
			}
		}
		return path[0][0];
	}
};

void test() {
	vector<vector<int>> obs = {{1}};
	cout << (new Solution)->uniquePathsWithObstacles(obs);
}