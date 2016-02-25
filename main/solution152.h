#pragma once
//152. Maximum Product Subarray
//https ://leetcode.com/problems/maximum-product-subarray/

#include "leetCodeHead.h"

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		int pre(1), neg(1), aft(1);
		int max = 0;
		for (auto ele : nums) {
			if (ele > 0) {
				if (neg > 0) {
					pre *= ele;
					max = max > pre ? max : pre;
				} else {
					aft *= ele;
					max = max > aft ? max : aft;
				}
			} else if (ele < 0) {
				if (neg > 0) {
					neg = ele;
				} else {
					pre = pre * neg * aft * ele;
					max = max > pre ? max : pre;
					neg = 1;
				}
			} else {
				pre = 1;
				aft = 1;
				neg = 1;
			}
		}
		return max;
	}
};

void test() {
	vector<int> v = {1,2,0,3,-2,4,0,2,-2};
	Solution s;
	cout << s.maxProduct(v);
}