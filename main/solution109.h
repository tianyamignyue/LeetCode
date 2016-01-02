#pragma once

//109. Convert Sorted List to Binary Search Tree
//https ://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include "leetCodeHead.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
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
	TreeNode* buildBST(ListNode* head, int length) {
		if (head == NULL || length <= 0)
			return NULL;
		int half = length >> 1;
		ListNode *p = head;
		while ((p) && half--) {
			p = p->next;
		}
		half = length >> 1;
		TreeNode *root = new TreeNode(p->val);
		root->left = buildBST(head, half);
		root->right = buildBST(p->next, length - half - 1);
		return root;
	}
public:
	TreeNode* sortedListToBST(ListNode* head) {
		int length = 0;
		ListNode *p = head;
		while (p != NULL) {
			p = p->next;
			++length;
		}
		return buildBST(head, length);
	}
};

void test() {
	vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
	Solution s;
	s.sortedListToBST(buildList(nums));
}