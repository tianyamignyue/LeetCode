#pragma once
#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;
		int length = 0;
		ListNode *p = head;
		while (p != NULL) {
			p = p->next;
			++length;
		}
		ListNode *newHead = head;
		ListNode *pre = head;
		head = head->next;
		pre->next = NULL;
		for (int i = 1; i < length / 2; ++i) {
			newHead = head;
			head = head->next;
			newHead->next = pre;
			pre = newHead;
		}
		if (length % 2 != 0) {
			head = head->next;
		}
		while (head != NULL) {
			if (head->val != newHead->val)
				return false;
			head = head->next;
			newHead = newHead->next;
		}
		return true;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	(new Solution)->isPalindrome(head);
	return 0;
}