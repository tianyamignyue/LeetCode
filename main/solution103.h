#pragma once
//103. Binary Tree Zigzag Level Order Traversal		https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<TreeNode*> level;
		vector<vector<int>> result;
		vector<int> row;
		if (root == NULL)
			return result;
		level.push_back(root);
		int leftToRight = true;
		while (!level.empty()) {
			int size = level.size();
				for (int i = 0; i < size; ++i) {
					row.push_back(level[i]->val);
					if (level[i]->right)
						level.push_back(level[i]->right);
					if (level[i]->left)
						level.push_back(level[i]->left);
				}
			if(!(leftToRight^=1))
				row.swap(*(new vector<int>(row.rbegin(),row.rend())));
			level.erase(level.begin(), level.begin() + size);
			if (!row.empty()) {
				result.push_back(row);
				row.clear();
			}
		}
		return result;
	}
};

void test() {
	//{3, 9, 20, #, #, 15, 7},
	TreeNode * root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution s;
	printvv(s.zigzagLevelOrder(root));
}