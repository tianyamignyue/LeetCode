#pragma once
#include <iostream>
using namespace std;
/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p = head, *q = head;
		int i = 0;
		while (i++ < n)
			q = q->next;
		if (q == NULL) {
			q = head->next;
			delete(head);
			return q;
		}
		while (q->next != NULL) {
			p = p->next;
			q = q->next;
		}
		q = p->next;
		p->next = q->next;
		delete(q);
		return head;
	}
};

int main()
{
	ListNode* head = new ListNode(1);
	(new Solution)->removeNthFromEnd(head, 1);
	return 0;
}