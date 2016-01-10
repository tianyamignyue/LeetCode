#pragma once

//131. Palindrome Partitioning
//https ://leetcode.com/problems/palindrome-partitioning/

#include "leetCodeHead.h"

class Solution {
	bool isPalindrome(string& s, int begin, int end) {
		if (begin >= end)
			return false;
		--end;
		while (begin < end) {
			if (s[begin] != s[end]) {
				return false;
			}
			++begin, --end;
		}
		return true;
	}

	void bt(string& s, int begin, int index, vector<string>& partition, vector<vector<string>>& result) {
		if (index == s.size()) {
			if (isPalindrome(s, begin, index)) {
				partition.push_back(s.substr(begin, index));
				result.push_back(partition);
				partition.pop_back();
				return;
			}
			else {
				return;
			}
		}
		if (isPalindrome(s, begin, index + 1)) {
			partition.push_back(s.substr(begin, index + 1 - begin));
			bt(s, index + 1, index + 1, partition, result);
			partition.pop_back();
		}
		bt(s, begin, index + 1, partition, result);
	}

public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> partition;
		bt(s, 0, 0, partition, result);
		return result;
	}
};

void test() {
	string str = "seeslaveidemonstrateyetartsnomedievalsees";
	vector<vector<string>> result;
	Solution s;
	result = s.partition(str);
	printvv(result);
}