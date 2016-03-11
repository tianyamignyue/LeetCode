#pragma once
//173. Binary Search Tree Iterator
//https ://leetcode.com/problems/binary-search-tree-iterator/

#include "leetCodeHead.h"

class BSTIterator {
	stack<TreeNode*> m_stack;
public:
	BSTIterator(TreeNode *root) {
		while (root != nullptr) {
			m_stack.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return ! m_stack.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *p = m_stack.top();
		m_stack.pop();
		int val = p->val;
		p = p->right;
		while (p != nullptr) {
			m_stack.push(p);
			p = p->left;
		}
		return val;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/

void test() {
	vector<int> v = { 5, 3, 7, 1, 4, 6, 9, NO_VALUE, 2, NO_VALUE, NO_VALUE, NO_VALUE,NO_VALUE , 8, NO_VALUE };
	TreeNode * root = buildTree(v);
	printTree(root, 1);
	BSTIterator i = BSTIterator(root);
	while (i.hasNext()) cout << i.next() << " ";
	cout << endl;
}