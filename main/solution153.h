#pragma once
//153. Find Minimum in Rotated Sorted Array
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include "leetCodeHead.h"

class Solution {
	int findMin(vector<int>&nums, int start, int end) {
		if (end - start <= 1)
			return nums[start];
		if (end - start == 2)
			return nums[start] < nums[start + 1] ? nums[start] : nums[start+1];
		int mid = (start + end) / 2;
		if (nums[mid] > nums[start] && nums[mid] > nums[end - 1])
			return findMin(nums, mid + 1, end);
		if (nums[mid] < nums[start] && nums[mid] < nums[end - 1])
			return findMin(nums, start, mid + 1);
		else
			return findMin(nums, start, mid);
	}
public:
	int findMin(vector<int>& nums) {
		return findMin(nums, 0, nums.size());
	}
};

void test() {
	vector<int> nums = {3,1,2};
	Solution s;
	cout << s.findMin(nums);
}