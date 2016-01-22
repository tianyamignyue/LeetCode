#pragma once
//148. Sort List
//https ://leetcode.com/problems/sort-list/

#include "leetCodeHead.h"

class Solution {
	ListNode* getMid(ListNode*& head) {
		ListNode *pre = head, *node = head;
		int n = length(head);
		n >>= 1;
		while (n  && node) {
			--n;
			pre = node;
			node = node->next;
		}
		if (pre != head)
			pre->next = nullptr;
		else
			head->next = nullptr;
		return node;
	}

	int length(ListNode* head) {
		int l = 0;
		while (head) {
			head = head->next;
			++l;
		}
		return l;
	}
public:
	ListNode* sortList(ListNode* head) {
		if (!head) {
			return nullptr;
		}
		if (!head->next) {
			return head;
		}
		ListNode* mid = getMid(head);
		if(head && head->next)
			head = sortList(head);
		if(mid && mid->next)
			mid = sortList(mid);
		ListNode* newList = nullptr, *p;
		if (head && mid) {
			if (head->val <= mid->val) {
				newList = head;
				head = head->next;
			} else {
				newList = mid;
				mid = mid->next;
			}
		} else if (head) {
			newList = head;
			head = head->next;
		} else if (mid) {
			newList = mid;
			mid = mid->next;
		} else {
			return nullptr;
		}
		p = newList;
		while (head && mid) {
			if (head->val <= mid->val) {
				p->next = head;
				head = head->next;
			} else {
				p->next = mid;
				mid = mid->next;
			}
			p = p->next;
		}
		while (head) {
			p->next = head;
			head = head->next;
			p = p->next;
		}
		while (mid) {
			p->next = mid;
			mid = mid->next;
			p = p->next;
		}
		return newList;
	}
};

void test() {
	ListNode *head = buildList({4,3,2,1});
	Solution s;
	head = s.sortList(head);
}