#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0)
			return 0;
		int n = grid[0].size();
		vector<vector<int>> cost;
		for (int i = m - 1; i >= 0; --i) {
			vector<int> row(n, 0);
			cost.push_back(row);
		}
		//last row
		int i = m - 1;
		int j = n - 1;
		//last one
		cost[i][j] = grid[i][j];
		--j;
		while (j >= 0) {
			cost[i][j] = grid[i][j] + cost[i][j + 1];
			--j;
		}
		for (i = m - 2; i >= 0; --i) {
			//last one in a row
			cost[i][n - 1] = grid[i][n - 1] + cost[i + 1][n - 1];
			for (j = n - 2; j >= 0; --j) {
				int right = grid[i][j] + cost[i][j + 1];
				int down = grid[i][j] + cost[i + 1][j];
				cost[i][j] = right < down ? right : down;
			}
		}
		return cost[0][0];
	}
};

void test() {
	vector<vector<int>> obs = { { 1 ,2},{3,4} };
	cout << (new Solution)->minPathSum(obs);
}