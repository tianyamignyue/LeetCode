#pragma once
//162. Find Peak Element
//https ://leetcode.com/problems/find-peak-element/
#include "leetCodeHead.h"

class Solution {
	int findPeakElement(vector<int>& nums, int start, int end) {
		if (start >= end)
			return -1;
		int mid = (start + end) / 2;
		if (mid == 0 && nums[0] > nums[1]){
			return 0;
		}
		if (mid == nums.size() - 1 && *(nums.end() - 2) < nums.back()){
			return nums.size() - 1;
		}
		if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
			return mid;
		}
		int r = findPeakElement(nums, start, mid);
		if (r > -1)
			return r;
		r = findPeakElement(nums, mid + 1, end);
		if (r > -1)
			return r;
		return -1;
	}
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1)
			return 0;
		return findPeakElement(nums, 0, nums.size());
	}
};

void test() {
	vector<int> v = { 1,2 };
	vector<int> v2 = { 2,1 };
	Solution s;
	cout << s.findPeakElement(v) << endl;
	cout << s.findPeakElement(v2) << endl;
}