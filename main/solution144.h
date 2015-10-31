#pragma once
#include <iostream>
#include <vector>
#include <stack>
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
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> res;
		TreeNode* p;
		if (root == NULL)
			return res;
		s.push(root);
		while (!s.empty()) {
			p = s.top();
			s.pop();
			res.push_back(p->val);
			if (p->right != NULL)
				s.push(p->right);
			if (p->left != NULL)
				s.push(p->left);
		}
		return res;
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
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);*/
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
	vector<int>res = s.preorderTraversal(root);
	int i = 0;
	while (i<res.size())
		cout << res[i++] << ' ';
	cout << endl;
	return 0;
}