#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> level, res;
		if (rowIndex <= 0)
			return res;
		level.push_back(1);
		for (int i = 0; i < rowIndex; i++) {
			res.push_back(1);
			for (int j = 0; j < (int)level.size() - 1; j++) {
				res.push_back(level[j] + level[j + 1]);
			}
			if (level.size() >= 1)
				res.push_back(1);
			level = res;
			res.resize(0);
		}
		return level;
	}
	vector<vector<int>> generate(int numRows) {
		vector<int> level;
		vector<int> nextL;
		vector<vector<int>> res;
		for (int i = 0; i < numRows; i++) {
			nextL.push_back(1);
			int j;
			for (j = 0; j < (int)level.size() - 1; j++) {
				nextL.push_back(level[j] + level[j + 1]);
			}
			if (level.size() > 0) {
				nextL.push_back(1);
			}
			res.push_back(nextL);
			level = nextL;
			nextL.resize(0);
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> res = s.getRow(1);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}