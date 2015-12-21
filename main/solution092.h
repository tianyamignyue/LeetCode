#pragma once
#include "leetCodeHead.h"

//Reverse Linked List II	https://leetcode.com/problems/reverse-linked-list-ii/

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m < 1)
			return head;
		ListNode *p, *pre, *last, *node, *tl;
		tl = pre = p = last = head;
		//process m == 1
		if (m == 1) {
			int num = m;
			while (p != NULL && num <= n) {
				node = p;
				p = p->next;
				//head insert
				if (node == head)
					node->next = NULL;
				else
					node->next = head;
				head = node;
				++num;
			}
			if (p != NULL) {
				tl->next = p;
			}
			return head;
		}

		for (int i = 2; i < m && last != NULL; ++i) {
			last = last->next;
		}
		tl = p = last->next;
		int num = m;
		while (p != NULL && num <= n) {
			node = p;
			p = p->next;
			//head insert
			if (node == last->next)
				node->next = NULL;
			else
				node->next = last->next;
			last->next = node;
			++num;
		}
		if (p != NULL) {
			tl->next = p;
		}
		return head;
	}
};

void test() {
	ListNode *head = new ListNode(1),*p;
	p = head;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);
	p = p->next;

	Solution s;
	head = s.reverseBetween(head, 2,4);
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
}