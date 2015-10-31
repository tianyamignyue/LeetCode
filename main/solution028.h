#pragma once
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int *next;
	int nextNum;
	void getNext(string s2) {
		int *next = this->next;
		int nextNum = this->nextNum;
		memset(next, 0, sizeof(next));
		int i = -1, j = 0;
		next[0] = -1;
		while (j<s2.length())
		{
			if (i == -1 || s2[i] == s2[j]) {
				i++; j++;
				next[j] = i;
			}
			else
				i = next[i];
		}
	}

	int strStr(string haystack, string needle) {
		int len1 = haystack.length(), len2 = needle.length();
		if (len1 < len2)
			return -1;
		for (int i = 0; i < len1 - len2 + 1;) {
			int j = 0;
			while (j < len2 && haystack[i] == needle[j]) {
				j++;
				i++;
			}
			if (j == len2)
				return i - j;
			else
				i = i - j + 1;
		}
		return -1;
	}
};

int main()
{
	Solution s;
	cout << s.strStr("abcabcdabcdeabcddfr", "abcd");
	return 0;
}