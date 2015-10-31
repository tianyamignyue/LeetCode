#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* newHead = head;
		ListNode *p = head, *next;
		if (head != NULL && head->next != NULL) {
			next = p->next;
		}
		else {
			return newHead;
		}
		while (next != NULL) {
			p->next = next->next;   //ȡ��
			next->next = newHead;  //ǰ��
			newHead = next;         //��ͷ
			next = p->next;         //���ƣ���һ��
		}
		return newHead;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	(new Solution)->reverseList(head);
	vector<int> v;
	//v.erase(v.begin());
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(1, 100));
	cout << m.size();

	return 0;
}