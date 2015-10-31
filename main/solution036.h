#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	bool containsDuplicate(vector<char>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < (int)nums.size() - 1; i++) {
			if (nums[i] == nums[i + 1])
				return true;
		}
		return false;
	}
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<char> row[9];
		vector<char> col[9];
		vector<char> grid[9];
		char c;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				c = board[i][j];
				if (c != '.') {
					row[i].push_back(c);
					col[j].push_back(c);
					grid[i / 3 * 3 + j / 3].push_back(c);
				}
			}
		}
		for (int i = 0; i< 9; i++) {
			if (containsDuplicate(row[i]) || containsDuplicate(col[i]) || containsDuplicate(grid[i]))
				return false;
		}
		return true;
	}
};

int main()
{
	return 0;
}