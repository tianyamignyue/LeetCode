#pragma once
//
//108. Convert Sorted Array to Binary Search Tree
//https ://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include "leetCodeHead.h"

class Solution {
	void buildBST(vector<int>::iterator begin, vector<int>::iterator end, TreeNode* &root) {
		if (begin >= end)
			return;
		auto mid = begin + ((end - begin) >> 1);
		root = new TreeNode(*mid);
		buildBST(begin, mid, root->left);
		buildBST(mid + 1, end, root->right);
		return;
	}
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode *root = NULL;
		if (!nums.empty())
			buildBST(nums.begin(), nums.end(), root);
		return root;
	}
};

void test() {
	vector<int> nums = { 0,1,2,3,4,5,6,7,8,9 };
	Solution s;
	s.sortedArrayToBST(nums);
}