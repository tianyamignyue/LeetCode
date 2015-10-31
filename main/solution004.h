#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
		if (nums2.size() < nums1.size())
			return findKth(nums2, nums1, k);
		if (nums1.size() == 0)
			return nums2[k - 1];
		if (k == 1)
			return nums1[0] < nums2[0] ? nums1[0] : nums2[0];
		int i1 = nums1.size() < k / 2 ? nums1.size() : k / 2;
		int i2 = k - i1;
		int kth1 = nums1[i1 - 1];
		int kth2 = nums2[i2 - 1];
		if (kth1 < kth2) {
			vector<int> tmp1 = vector<int>(nums1.begin() + i1, nums1.end());
			return findKth(tmp1, nums2, k - i1);
		}
		else if (kth1 > kth2) {
			vector<int> tmp2 = vector<int>(nums2.begin() + i2, nums2.end());
			return findKth(nums1, tmp2, k - i2);
		}
		else {
			return kth1;
		}
	}
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		auto length = nums1.size() + nums2.size();
		if (length % 2) {
			return findKth(nums1, nums2, length / 2 + 1);
		}
		else {
			return (findKth(nums1, nums2, length / 2) + findKth(nums1, nums2, length / 2 + 1)) / 2.0;
		}
	}
};

int test004()
{
	vector<int> num1 = { 1,3,5 };
	vector<int> num2 = { 2,4,6,8,9 };
	cout << (new Solution)->findMedianSortedArrays(num1, num2);
	return 0;
}