#pragma once

//113. Path Sum II
//https ://leetcode.com/problems/path-sum-ii/

#include "leetCodeHead.h"

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
	vector<vector<int>> result;
	vector<int> path;
	int m_sum;
	int target;
	void visit(TreeNode* root) {
		path.push_back(root->val);
		m_sum += root->val;
		if (!root->left && !root->right && m_sum == target) {
			result.push_back(path);
		}
	}
	void clearTrace(TreeNode* root) {
		path.pop_back();
		m_sum -= root->val;
	}
	void preOrderTraversal(TreeNode* root) {
		if (!root)
			return;
		visit(root);
		//cut branch
		//if (m_sum < target) {
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
		//}
		clearTrace(root);
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		m_sum = 0;
		target = sum;
		preOrderTraversal(root);
		return result;
	}
};

void test() {
	vector<int> nums = {5,4,8,11,NO_VALUE,13,4,7,2,NO_VALUE, NO_VALUE, 5,1};
	TreeNode *root = buildTree(nums);
	Solution s;
	vector<vector<int>> result;
	result = s.pathSum(root, 22);
	printvv(result);
}