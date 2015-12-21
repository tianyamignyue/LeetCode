#pragma once

//Subsets II		https://leetcode.com/problems/subsets-ii/

#include "leetCodeHead.h"


class Solution {

	vector<vector<int>> result;
	void dfs(vector<int> &nums, int index, vector<int> &subset) {
		if (index >= nums.size())
			return;

		//visit this node
		subset.push_back(nums[index]);
		result.push_back(subset);
		
		//visit other node
		dfs(nums, ++index, subset);
		for ( ++index; index < nums.size(); ++index) {
			while (index < nums.size() && index > 0 && nums[index - 1] == nums[index])
				++index;
			if(index < nums.size())
				dfs(nums, index, subset);
		}

		//clear trace
		subset.pop_back();
		return;
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		result.clear();
		vector<int> subset;
		result.push_back(subset);
		dfs(nums, 0, subset);
		for (int i = 1; i < nums.size(); ++i) {
			while (i < nums.size() && i > 0 && nums[i - 1] == nums[i])
				++i;
			if (i < nums.size())
				dfs(nums, i, subset);
		}
		return result;
	}
};

void test() {
	vector<vector<int>> result;
	vector<int> nums = { 1,2,2,2 };
	Solution s;
	result = s.subsetsWithDup(nums);
	int i = 0;
	for (auto row : result) {
		cout << ++i << ":\t[";
		for (auto ele : row) {
			cout << ele << ", ";
		}
		cout << "]" << endl;
	}
}