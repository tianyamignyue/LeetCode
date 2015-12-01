//Definition for singly-linked list.
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || k <= 0)
			return head;
		ListNode *p = head;
		int oriK = k;
		while (k){
			while (p != NULL && k){
				p = p->next;
				--k;
			}
			if (p == NULL){
				k = k % (oriK - k);
				p = head;
			}
		}
		ListNode *q = head;
		while (p->next != NULL){
			q = q->next;
			p = p->next;
		}
		p->next = head;
		head = q->next;
		q->next = NULL;
		return head;
	}
};

void test(){
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	Solution s;
	ListNode *newhead = s.rotateRight(head,7);

	while (newhead != NULL){
		cout << newhead->val << " ";
		newhead = newhead->next;
	}
	cout << endl;
}
