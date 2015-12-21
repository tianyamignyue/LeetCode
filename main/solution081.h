#pragma once
#include <vector>
#include <iostream>
using namespace std;
//process the duplicates
class Solution {
	bool RBsearch(vector<int> &nums, int start, int end, int target) {
		if (end - start <= 0)
			return false;
		int mid = (start + end) / 2;
		int index1, index2;
		if (nums[mid] == target) {
			return true;
		}
		int bmid, amid;
		bmid = amid = mid;
		while (bmid < end && nums[bmid] == nums[mid]) {
			++bmid;
		}
		while (amid >= 0 && nums[amid] == nums[mid]) {
			--amid;
		}
		if (nums[bmid] < nums[end - 1])
			index1 = Bsearch(nums, bmid, end, target);
		else
			index1 = RBsearch(nums, bmid, end, target);

		if (nums[start] < nums[amid + 1])
			index2 = Bsearch(nums, start, amid + 1, target);
		else
			index2 = RBsearch(nums, start, amid + 1, target);
		return index1 || index2;
	}
	bool Bsearch(vector<int> &nums, int start, int end, int target) {
		if (end - start <= 0)
			return false;
		int mid = (start + end) / 2;
		if (nums[mid] < target) {
			while (mid + 1 < end && nums[mid + 1] == nums[mid]) {
				++mid;
			}
			return Bsearch(nums, mid + 1, end, target);
		}
		else if (nums[mid] > target) {
			while (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
				--mid;
			}
			return Bsearch(nums, start, mid, target);
		}
		else {
			return true;
		}
	}
public:
	bool search(vector<int>& nums, int target) {
		return RBsearch(nums, 0, nums.size(), target);
	}
};

void test() {
	vector<int> nums = {4,5,6,7,0,1,2};
	Solution s;
	cout << s.search(nums,4);
}