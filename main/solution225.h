#pragma once
#include <iostream>
#include <queue>
using namespace std;

class Stack {
	queue<int> q;
	int t;
public:
	// Push element x onto stack.
	void push(int x) {
		q.push(x);
		t = x;
	}

	// Removes the element on top of the stack.
	void pop() {
		int n = q.size(), temp;
		while (n > 1) {
			temp = q.front();
			q.pop();
			q.push(temp);
			t = temp;
			--n;
		}
		q.pop();
	}

	// Get the top element.
	int top() {
		return t;
	}

	// Return whether the stack is empty.
	bool empty() {
		return q.empty();
	}
};

int main()
{
	return 0;
}