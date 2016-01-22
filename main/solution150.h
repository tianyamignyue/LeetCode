#pragma once
//150. Evaluate Reverse Polish Notation
//https ://leetcode.com/problems/evaluate-reverse-polish-notation/

#include "leetCodeHead.h"

class Solution {
	enum type {
		interger,
		add,
		minus,
		multi,
		divide
	};
	type getType(const string& str) {
		if (str.length() > 1)
			return interger;
		switch (str[0]) {
		case '+':
			return add;
		case '*':
			return multi;
		case '-':
			return minus;
		case '/':
			return divide;
		default:
			return interger;
		}
	}
public:
	int evalRPN(vector<string>& tokens) {
		vector<int> stk;
		int a;
		int b;
		for (const auto& str : tokens) {
			switch (getType(str)) {
			case add:
			{
				b = stk.back();
				stk.pop_back();
				a = stk.back();
				stk.pop_back();
				stk.push_back(a + b);
				break;
			}
			case multi:
			{
				b = stk.back();
				stk.pop_back();
				a = stk.back();
				stk.pop_back();
				stk.push_back(a * b);
				break;
			}
			case minus:
			{
				b = stk.back();
				stk.pop_back();
				a = stk.back();
				stk.pop_back();
				stk.push_back(a - b);
				break;
			}
			case divide:
			{
				b = stk.back();
				stk.pop_back();
				a = stk.back();
				stk.pop_back();
				stk.push_back(a / b);
				break;
			}
			default:
			{
				stk.push_back(stoi(str));
				break;
			}
			}
		}
		return stk.back();
	}
};

void test() {
	vector<string> v = { "4", "-13", "+"};
	Solution s;
	cout << s.evalRPN(v);
}