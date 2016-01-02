#pragma once

//	95. Unique Binary Search Trees II		https://leetcode.com/problems/unique-binary-search-trees-ii/
#include "leetCodeHead.h"

class Solution {
	void generateTrees(int start, int end, vector<TreeNode*> &result){
		if (end < start) {
			result.push_back(NULL);
			return ;
		}
		for (int i = start; i <= end; ++i) {
			vector<TreeNode *> leftTrees, rightTrees;
			generateTrees(start, i-1, leftTrees);
			generateTrees(i+1, end, rightTrees);
			for (auto left : leftTrees) {
				for (auto right : rightTrees) {
					TreeNode * root = new TreeNode(i);
					root->left = left;
					root->right = right;
					result.push_back(root);
				}
			}
		}
	}
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> result;
		generateTrees(1, n, result);
		if (result.size() == 1 && result[0] == NULL)
			result.clear();
		return result;
	}
};

void test() {
	Solution s;
	vector<TreeNode*> result = s.generateTrees(3);
}

