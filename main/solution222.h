#pragma once
#include "leetCodeHead.h"
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int ll(0), rl(0);
		TreeNode* p = root;
		while (p) {
			p = p->left;
			++ll;
		}
		p = root;
		while (p) {
			p = p->right;
			++rl;
		}
		if (ll == rl) {
			return (2 << ll-1) - 1;
		} else {
			int left = countNodes(root->left);
			int right = countNodes(root->right);
			return  left + right + 1;
		}
	}
};


void test() {
	vector<int> vet = {1,2,3,4,5};

	TreeNode* p = buildTree(vet);

	Solution s;
	cout << s.countNodes(p);


}