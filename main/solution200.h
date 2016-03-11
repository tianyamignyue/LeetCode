#pragma once
//https://leetcode.com/problems/number-of-islands/
//200. Number of Islands

#include "leetCodeHead.h"


class Solution {
	void deleteIsland(vector<vector<char>>& grid, int i, int j) {
		int m = grid.size();
		int n = grid[0].size();
		list<pair<int, int>> q;
		q.push_back(pair<int, int>(i, j));
		while (!q.empty()) {
			auto loc = q.front();
 			q.pop_front();
			if (grid[loc.first][loc.second] == '1') {
				grid[loc.first][loc.second] = '0';
			} else {
				continue;
			}

			if (loc.second - 1 >= 0 && grid[loc.first][loc.second - 1] == '1') {
				q.push_back(pair<int, int>(loc.first, loc.second - 1));
			}
			if (loc.second + 1 < n && grid[loc.first][loc.second + 1] == '1') {
				q.push_back(pair<int, int>(loc.first, loc.second + 1));
			}
			if (loc.first - 1 >= 0 && grid[loc.first - 1][loc.second] == '1') {
				q.push_back(pair<int, int>(loc.first - 1, loc.second));
			}
			if (loc.first + 1 < m && grid[loc.first + 1][loc.second] == '1') {
				q.push_back(pair<int, int>(loc.first + 1, loc.second));
			}
		}
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		int n = grid.size();
		if (!n) {
			return 0;
		}
		int m = grid[0].size();
		if (!m) {
			return 0;
		}
		int num = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == '1') {
					++num;
					deleteIsland(grid, i, j);
				}
			}
		}
		return num;
	}
};

void test() {
	Solution s;
	//vector<vector<char>> grid = { {'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'} };
	vector<vector<char>> grid = { { '1','1','1' },{ '0','1','0' },{ '1','1','1' } };
	cout << s.numIslands(grid);
}