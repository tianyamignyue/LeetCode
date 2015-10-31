#pragma once
#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;

/**
* Definition for a binary tree node.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == p || root == q)
			return root;
		int max, min, vp, vq, vr;
		vp = p->val;
		vq = q->val;
		vr = root->val;
		max = vp > vq ? vp : vq;
		min = vp < vq ? vp : vq;
		if (vr > max)
			return lowestCommonAncestor(root->left, p, q);
		else if (vr < min)
			return lowestCommonAncestor(root->right, p, q);
		else
			return root;
	}
};
int main()
{
	/*
	_______6______
	/		      \
	___2__          ___8__
	/      \        /      \
	0      _4       7       9
	/  \
	3   5
	*/
	TreeNode *root = new TreeNode(6);
	root->left = new TreeNode(2);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);
	root->left->right->right = new TreeNode(5);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);

	Solution s;
	TreeNode *ans1 = s.lowestCommonAncestor(root, root->left->left, root->left->right);
	cout << ans1->val;

	return 0;
}