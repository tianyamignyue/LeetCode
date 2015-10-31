#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
	vector<string> words;
	void getWords(string str) {
		string subs = "";
		for (auto i = str.begin(); i != str.end(); ++i) {
			if (*i != ' ') {
				subs += *i;
			}
			else {
				words.push_back(subs);
				subs = "";
			}
		}
		words.push_back(subs);
	}
public:
	bool wordPattern(string pattern, string str) {
		map<char, int> key_index;
		map<string, int> word_index;
		getWords(str);
		auto i = pattern.begin();
		auto j = words.begin();
		for (; i != pattern.end() && j != words.end(); ++i, ++j) {
			auto it_p = key_index.find(*i);
			auto it_w = word_index.find(*j);
			if (it_p != key_index.end()) {
				if (it_w == word_index.end() || it_w->second != it_p->second)
					return false;
			}
			else {
				if (it_w != word_index.end())
					return false;
				else {
					key_index.insert(pair<char, int>(*i, i - pattern.begin()));
					word_index.insert(pair<string, int>(*j, j - words.begin()));
				}
			}
		}
		return true;
	}
};

int main()
{
	cout << (new Solution)->wordPattern("abba", "dog cat cat fish");
	return 0;
}