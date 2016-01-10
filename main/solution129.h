#pragma once

//129. Sum Root to Leaf Numbers
//https ://leetcode.com/problems/sum-root-to-leaf-numbers/

#include "leetCodeHead.h"

class Solution {
	void dfs(TreeNode* root, int subval, int& sum) {
		subval = subval * 10 + root->val;
		if (root->left == nullptr && root->right == nullptr) {
			sum += subval;
			return;
		}
		if (root->left) {
			dfs(root->left, subval, sum);
		}
		if (root->right) {
			dfs(root->right, subval, sum);
		}
		return;
	}


public:
	int sumNumbers(TreeNode* root) {
		int subval = 0, sum = 0;
		if (root == nullptr)
			return 0;
		dfs(root, subval, sum);
		return sum;
	}
};

void test() {
	vector<int> v = {1,NO_VALUE, 5};
	Solution s;
	cout << s.sumNumbers(buildTree(v));
}