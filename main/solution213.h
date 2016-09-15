#pragma once
//213. House Robber II
#include "leetCodeHead.h"
class Solution {
	inline int MAX(int x, int y) {
		return x > y ? x : y;
	}
public:
	int rob(vector<int>& nums) {
		if (!nums.size()) {
			return 0;
		}
		if (nums.size() == 1) {
			return nums[0];
		}
		if (nums.size() == 2) {
			return MAX(nums[0], nums[1]);
		}
		vector<int> money1(nums.size(), 0);
		vector<int> money2(nums.size(), 0);
		money1[0] = nums[0];
		money1[1] = MAX(nums[0], nums[1]);

		money2[0] = nums[1];
		money2[1] = MAX(nums[1], nums[2]);

		for (int i = 2; i < nums.size() - 1; ++i) {
			money1[i] = MAX(money1[i - 1], money1[i - 2] + nums[i]);
			money2[i] = MAX(money2[i - 1], money2[i - 2] + nums[i + 1]);
		}
		return MAX(*(money1.end() - 2), *(money2.end() - 2));
	}
};

void test() {
	vector<int> nums = {3,1,4,1,5,9,2,6};
	Solution s;

	cout << s.rob(nums);
}