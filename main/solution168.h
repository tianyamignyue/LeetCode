#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string res = "";
		stack<char> s;
		int mod;
		while (n != 0) {
			mod = (n - 1) % 26 + 1;
			s.push('A' + mod - 1);
			n = (n - 1) / 26;
		}
		while (!s.empty()) {
			res += s.top();
			s.pop();
		}
		return res;
	}
};

int main()
{
	Solution s;
	cout << s.convertToTitle(1) << endl;
	cout << s.convertToTitle(26) << endl;
	cout << s.convertToTitle(27) << endl;
	cout << s.convertToTitle(51) << endl;
	cout << s.convertToTitle(52) << endl;
	cout << s.convertToTitle(53) << endl;
	vector<int> v;
	auto i = v.begin();
	return 0;
}