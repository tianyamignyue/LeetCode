#pragma once
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

#include "leetCodeHead.h"

class Solution {
	bool isBST(TreeNode *root, int &max, int &min) {
		if (!root) {
			max = MIN_INT;
			min = MAX_INT;
			return true;
		}
		int max1(MIN_INT), min1(MAX_INT), max2(MIN_INT), min2(MAX_INT);
		if (root->left && !isBST(root->left, max1, min1))
			return false;
		if (root->right && !isBST(root->right, max2, min2))
			return false;
		max = root->val > max1 ? root->val : max1;
		max = max > max2 ? max : max2;
		min = root->val < min1 ? root->val : min1;
		min = min < min2 ? min : min2;
		if (root->left && max1 >= root->val)
			return false;
		if (root->right && min2 <= root->val)
			return false;
		return true;
	}
public:
	bool isValidBST(TreeNode* root) {
		int min(MAX_INT), max(MIN_INT);
		return isBST(root, max, min);
	}
};

void test() {
	TreeNode * root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	Solution s;
	cout << s.isValidBST(root);
}