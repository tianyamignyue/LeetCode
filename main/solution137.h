#pragma once

//137. Single Number II
//https://leetcode.com/problems/single-number-ii/

#include "leetCodeHead.h"

class Solution {
	int bit32[32];
	int getInt() {
		int x = 0;
		for (int i = 0; i < 32; ++i) {
			if (bit32[i] % 3 == 1) {
				x |= (1 << i);
			}
		}
		return x;
	}
	void saveInt(int x) {
		for (int i = 0; i < 32; ++i) {
			if (x & (1 << i)) {
				++bit32[i];
			}
		}
	}
	void init() {
		for (int i = 0; i < 32; ++i) {
			bit32[i] = 0;
		}
	}
public:
	int singleNumber(vector<int>& nums) {
		init();
		for (auto ele : nums) {
			saveInt(ele);
		}
		return getInt();
	}
};

void test() {
	vector<int> nums = { 2,2,2,10 };
	Solution s;
	cout << s.singleNumber(nums);
}