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
	bool isSymmetric(TreeNode* root) {
		queue<TreeNode*> q;
		if (root == NULL)
			return true;
		q.push(root);
		q.push(NULL);
		while (q.size() > 1) {
			TreeNode *subNode;
			subNode = q.front();
			q.pop();
			vector<int> level;
			while (subNode != NULL) {
				level.push_back(subNode->val);
				if (subNode->val == int(0x7fffffff)) {
					subNode = q.front();
					q.pop();
					continue;
				}
				if (subNode->left == NULL)
					subNode->left = new TreeNode(int(0x7fffffff));
				q.push(subNode->left);
				if (subNode->right == NULL)
					subNode->right = new TreeNode(int(0x7fffffff));
				q.push(subNode->right);
				subNode = q.front();
				q.pop();
			}
			while (level.size() > 1) {
				if (level[0] == level[level.size() - 1]) {
					level.erase(level.begin());
					level.erase(--level.end());
				}
				else {
					return false;
				}
			}

			q.push(NULL);
		}
		return true;
	}
};

int main()
{
	Solution s;
	TreeNode *root;
	root = new TreeNode(2);
	//root->left = new TreeNode(3);
	//root->right = new TreeNode(3);
	//root->left->left = new TreeNode(4);
	//root->right->left = new TreeNode(5);
	//root->right->right = new TreeNode(4);
	cout << s.isSymmetric(root);
	return 0;
}