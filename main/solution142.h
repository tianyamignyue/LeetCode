#pragma once
//142. Linked List Cycle II
//https ://leetcode.com/problems/linked-list-cycle-ii/

#include "leetCodeHead.h"

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head)
			return nullptr;
		ListNode *first = head, *second = head;
		do {
			second = second->next;
			first = first->next;
			if (first)
				first = first->next;
			else
				return nullptr;
		} while (first && first != second);
		if (!first)
			return nullptr;
		ListNode *third = head;
		while (third != second) {
			third = third->next;
			second = second->next;
		}
		return third;
	}
};

void test() {
	ListNode *head = buildList({-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5});
	//ListNode *p = head;
	//while (p->next != nullptr) {
	//	p = p->next;
	//}
	//p->next = head->next;
	Solution s;
	ListNode *node = s.detectCycle(head);
	cout << (node ? node->val : 1234567890);
}