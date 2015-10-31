#pragma once
#include <iostream>
#include <vector>
#include <queue>
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> q;
		if (root == NULL)
			return res;
		q.push(root);
		q.push(NULL);
		while (q.size() > 1) {
			TreeNode *subNode;
			subNode = q.front();
			q.pop();
			vector<int> level;
			while (subNode != NULL) {
				level.push_back(subNode->val);
				if (subNode->left != NULL)
					q.push(subNode->left);
				if (subNode->right != NULL)
					q.push(subNode->right);
				subNode = q.front();
				q.pop();
			}
			res.push_back(level);
			q.push(NULL);
		}
		return res;
	}
};

int main()
{
	/*
	3
	/ \
	9  20
	/  \
	15   7
	*/
	TreeNode *root;
	root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution s;
	vector<vector<int>> level;
	level = s.levelOrder(root);
	for (int i = 0; i < level.size(); i++) {
		vector<int> v = level[i];
		cout << i + 1 << ": \t";
		for (int j = 0; j < v.size(); j++) {
			cout << v[j] << " ";
		}
		cout << endl;
	}
	return 0;
}