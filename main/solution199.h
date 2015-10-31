#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> views;
		queue<TreeNode*> level;
		level.push(root);
		level.push(NULL);
		TreeNode *subNode;
		int lastValue;
		while (level.size() > 1) {
			subNode = level.front();
			level.pop();
			if (subNode == NULL) {
				views.push_back(lastValue);
				level.push(NULL);
				continue;
			}
			lastValue = subNode->val;
			if (subNode->left != NULL)
				level.push(subNode->left);
			if (subNode->right != NULL)
				level.push(subNode->right);
		}
		views.push_back(lastValue);
		return views;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(4);
	Solution s;
	vector<int> res = s.rightSideView(root);
	return 0;
}