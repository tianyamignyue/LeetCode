#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution014 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		string prefix = strs[0];
		string str;
		unsigned int j = 0;
		for (unsigned int i = 1; i < strs.size(); i++) {
			str = strs[i];
			for (j = 0; j < prefix.length() && j < str.length();) {
				if (prefix[j] == str[j])
					j++;
				else {
					break;
				}
			}
			prefix = prefix.substr(0, j);
		}
		return prefix;
	}
};

int main014()
{
	vector<string> strs;
	strs.push_back("a");
	strs.push_back("b");
	cout << (new Solution014)->longestCommonPrefix(strs);
	return 0;
}