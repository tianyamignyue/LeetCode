#pragma once
//105. Construct Binary Tree from Preorder and Inorder Traversal
//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include "leetCodeHead.h"

class Solution {
	void buildTree(vector<int> &preorder, vector<int>::iterator prebegin, vector<int>::iterator preend,
		vector<int> &inorder, vector<int>::iterator inbegin, vector<int>::iterator inend,
		TreeNode* &root) {
		if (inend <= inbegin)
			return;
		root  = new TreeNode(*prebegin);
		auto f = find(inbegin, inend, *prebegin);
		
		buildTree(preorder, prebegin + 1, prebegin + (f - inbegin) + 1,
			inorder, inbegin, f,
			root->left);
		buildTree(preorder, prebegin + (f - inbegin) + 1, preend,
			inorder, f + 1, inend,
			root->right);
		
	}
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty())
			return NULL;
		TreeNode *root;
		buildTree(preorder, preorder.begin(),preorder.end(),
			inorder, inorder.begin(), inorder.end(),
			root);
		return root;
	}
};

void test() {
/*
	[1, 2, 3, 6, 5, 4, 8, 0, 9]
	[3, 6, 2, 1, 4, 8, 5, 9, 0]*/

	vector<int> preo = { 1, 2, 3, 6, 5, 4, 8, 0, 9 };
	vector<int> ino = { 3, 6, 2, 1, 4, 8, 5, 9, 0 };

	Solution s;
	s.buildTree(preo, ino);

}