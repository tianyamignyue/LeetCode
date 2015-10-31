#pragma once
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		string lastWord = "";
		bool find = false;
		char c;
		for (int i = s.length() - 1; i >= 0; i--) {
			c = s[i];
			if (c != ' ') {
				lastWord += c;
				find = true;
			}
			else if (find)
				return lastWord.length();
		}
		if (find)
			return lastWord.length();
		else
			return 0;
	}
};

int main()
{
	Solution s;
	string str = "asd";
	cout << s.lengthOfLastWord("asd") << endl;
	return 0;
}