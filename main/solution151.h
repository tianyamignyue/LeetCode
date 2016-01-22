#pragma once
//151. Reverse Words in a String
//https ://leetcode.com/problems/reverse-words-in-a-string/

#include "leetCodeHead.h"
class Solution {
public:
	void reverseWords(string &s) {
		istringstream is(s);
		string temp;
		ostringstream os;
		vector<string> strv;
		while (is >> temp) {
			strv.push_back(temp);
		}
		if (strv.empty()) {
			s.clear();
			return;
		}
		for (auto start = strv.crbegin(); start != strv.crend(); ++start) {
			if ((*start).empty())
				continue;
			os << *start << ' ';
		}
		s.swap(os.str());
		if(!s.empty())
			s.pop_back();
	}
};

void test() {
	string s = " ";
	Solution sln;
	sln.reverseWords(s);
	cout << s;
}