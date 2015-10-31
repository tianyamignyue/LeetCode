#pragma once
#include <iostream>

using namespace std;


class Solution {
public:
	bool isAnagram(string s, string t) {
		unsigned sum1 = 0, sum2 = 0;
		if (s.length() != t.length())
			return false;
		for (int i = 0; i < s.length(); i++) {
			sum1 += s[i];
			sum2 += t[i];
		}
		if (sum1 == sum2)
			return true;
		else
			return false;
	}
};

int main()
{
	string s = "asdfg";
	string t = "gdfsa";
	cout << (new Solution)->isAnagram(s, t);
	return 0;
}