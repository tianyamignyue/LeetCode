#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//*
//* Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};