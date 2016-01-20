#pragma once
//147. Insertion Sort List
//https ://leetcode.com/problems/insertion-sort-list/

#include "leetCodeHead.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
	ListNode* insertNode(ListNode *head,ListNode *end, ListNode *node) {
		ListNode *newhead = head, *p, *next;
		if (!head)
			return nullptr;
		if (node->val < head->val) {
			newhead = node;
			node->next = head;
			return newhead;
		}
		p = head;
		next = p->next;
		while (p && p->next && p->next != node) {
			if (node->val >= next->val) {
				p = next;
				next = next->next;
			}
			else {
				break;
			}
		}
		node->next = p->next;
		p->next = node;
		return newhead;
	}
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode *newlist = nullptr;
		newlist = head;
		ListNode *next = head->next;
		newlist->next = nullptr;
		while (next) {
			ListNode *temp = next->next;
			newlist = insertNode(newlist,next, next);
			next = temp;
		}
		return newlist;
	}
};

void test() {
	ListNode *head = buildList({3,1,4,1,5,9,2,6});
	Solution s;
	head = s.insertionSortList(head);
}