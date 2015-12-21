#pragma once

#define NULL 0

//*
//* Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode *last, *p, *pre, *large;
		large = NULL;
		p = pre = head;
		while (p != NULL) {
			if (p->val >= x) {//将p拿下来，放到large中，同时维护pre和p
							  //拿下来
				ListNode *node;
				if (p == head) {
					head = p->next;
					pre = head;
					node = p;
					p = head;
				}
				else {
					pre->next = p->next;
					node = p;
					p = pre->next;
				}
				//放到large中；
				if (large == NULL) {
					large = node;
					last = node;
					node->next = NULL;
				}
				else {
					last->next = node;
					last = node;
					last->next = NULL;
				}
			}
			else {
				pre = p;
				p = p->next;
			}
		}
		if (pre != NULL)
			pre->next = large;
		else
			head = large;
		return head;
	}
};

void test() {
	ListNode *head;
	head = new ListNode(1);
	//head->next = new ListNode(1);

	Solution s;
	s.partition(head,2);


}