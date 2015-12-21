#pragma once
#include "leetCodeHead.h"

//Decode Ways https://leetcode.com/problems/decode-ways/

class Solution {
	bool isConn(int a, int b) {
		if (a == 1 || a == 2 && b >= 0 && b <= 6)
			return true;
		else
			return false;
	}
public:
	int numDecodings(string s) {
		int size = s.size();
		if (size < 1) {
			return size;
		}
		vector<int> conn(size, 0);
		vector<int> notConn(size, 0);
		conn[0] = 0;
		if (s[0] == '0') {
			notConn[0] = 0;
		}
		else {
			notConn[0] = 1;
		}
		for (int i = 1; i < size; ++i) {
			if (isConn(s[i - 1] - '0', s[i] - '0')) {
				conn[i] = notConn[i - 1];
			}
			else {
				conn[i] = 0;
			}
			if (s[i] == '0') {
				notConn[i] = 0;
			}
			else {
				notConn[i] = conn[i - 1] + notConn[i - 1];
			}
		}
		return conn[size - 1] + notConn[size - 1];
	}
};

void test() {
	Solution s;
	cout << s.numDecodings("17");
}