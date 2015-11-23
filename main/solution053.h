#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	int Dynamic(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		int begin = 0, end = 0;
		int maxnum, subnum;
		maxnum = subnum = nums[0];
		while (++end < nums.size()) {
			subnum += nums[end];
			maxnum > subnum ? maxnum : maxnum = subnum;
			if (subnum < 0) {
				begin = end + 1;
				begin < nums.size() ? subnum = nums[begin] : subnum;
				++end;
			}
		}
		return maxnum;
	}

public:
	int maxSubArray(vector<int>& nums) {
		return Dynamic(nums);
	}
};

void test() {
	cout << (new Solution)->maxSubArray(vector<int>({ -2,1,-3,4,-1,2,1,-5,4 }));
}