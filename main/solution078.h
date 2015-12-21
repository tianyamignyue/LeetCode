#pragma once
#include "leetCodeHead.h"

//    Subsets   https://leetcode.com/problems/subsets/

//using dfs
class Solution {
	vector<vector<int>> result;
	void dfs(vector<int> &nums, int index, vector<int> &subset) {
		if (index >= nums.size())
			return;
		//visit this node
		subset.push_back(nums[index]);
		result.push_back(subset);
		//visit other node
		for (++index; index < nums.size(); ++index) {
			dfs(nums, index, subset);
		}
		
		//clear trace
		subset.pop_back();
		return;
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		result.clear();
		vector<int> subset;
		result.push_back(subset);
		for (int i = 0; i < nums.size(); ++i) {
			dfs(nums, i, subset);
		}
		return result;
	}
};

void test() {
	vector<vector<int>> result;
	vector<int> nums = { 1,2,3,4 };
	Solution s;
	result = s.subsets(nums);
	int i = 0;
	for (auto row : result) {
		cout << ++i <<  ":\t[";
		for (auto ele : row) {
			cout << ele << ", ";
		}
		cout << "]" << endl;
	}
}