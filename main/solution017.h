#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		vector<string> work;
		if (digits.length() == 0)
			return res;
		string charsOfDigit[] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		string substr = charsOfDigit[digits[0] - '0'];
		for (auto i = 0; i < substr.size(); ++i) {
			string temp;
			temp += substr[i];
			work.push_back(temp);
		}
		work.swap(res);
		work.clear();
		for (auto i = digits.begin() + 1; i != digits.end(); ++i) {
			string substr = charsOfDigit[*i - '0'];
			for (auto j = 0; j < substr.size(); ++j) {
				for (auto k = res.begin(); k != res.end(); ++k) {
					string temp = *k;
					temp += substr[j];
					work.push_back(temp);
				}
			}
			work.swap(res);
			work.clear();
		}
		return res;
	}
};
int main()
{
	vector<string> res = (new Solution)->letterCombinations("2");

	for (auto i = res.begin(); i != res.end(); ++i) {
		cout << *i << "--" << (i - res.begin());
	}
	return 0;
}