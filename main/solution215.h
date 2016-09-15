#pragma once
//215. Kth Largest Element in an Array
//https://leetcode.com/problems/kth-largest-element-in-an-array/
#include "leetCodeHead.h"

class Solution {
public:
	int partition(vector<int>& nums, int start, int end, int partIndex) {
		if (start >= end) {
			return start;
		}
		int partVal = nums[partIndex];
		int temp;
		nums[partIndex] = nums[start];
		while (start < end) {
			//从后面找小的，填到start上
			while (start < end && nums[end] > partVal) {
				--end;
			}
			if (start == end) {
				break;
			}
			nums[start] = nums[end];
			++start;
			//从前面找大的，填到end上
			while (start < end && nums[start] < partVal) {
				++start;
			}
			if (start == end) {
				break;
			}
			nums[end] = nums[start];
			--end;
		}
		nums[start] = partVal;
		return start;
	}
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (k <= 0 || k > nums.size()) {
			return 0;
		}
		int start = 0;
		int end = nums.size();
		int partIndex = rand() % end;
		int storeIndex;

		do {
			storeIndex = partition(nums, start, end-1, partIndex);
			if (storeIndex < nums.size() - k) {
				start = storeIndex + 1;
			} else {
				end = storeIndex;
			}
			if (end == start)
				break;
			partIndex = start + rand() % (end - start);
		} while (storeIndex != nums.size() - k);
		return nums[storeIndex];
	}
};

void test() {
	vector<int> nums = { 3,2,1,5,6,4 };
	int k = 2;
	Solution s;
}