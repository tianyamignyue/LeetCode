#pragma once
//*
//* Definition for a binary tree node.
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		int depthl = 0, depthr = 0;
		if (root == NULL)
			return 0;
		if (root->left != NULL)
			depthl = maxDepth(root->left);
		if (root->right != NULL)
			depthr = maxDepth(root->right);
		return depthl > depthr ? depthl + 1 : depthr + 1;
	}
};