#pragma once
//139. Word Break
//https ://leetcode.com/problems/word-break/
// Accepted 24 ms
#include "leetCodeHead.h"
class Solution {
	bool wordBreak(string s, int index, string& substr, bool& subres, unordered_set<string>& wordDict) {
		if (index == s.size()) {
			if (subres && (!substr.size() || wordDict.end() != wordDict.find(substr)))
				return true;
			else
				return false;
		}
		bool ori_res = subres;
		string ori_str = substr;
		bool res = false;
		substr += s[index];
		auto f = wordDict.find(substr);
		if (f != wordDict.end()) {
			bool ori_res = subres;
			string ori_str = substr;
			subres = true;
			substr = "";
			if (wordBreak(s, index + 1, substr, subres, wordDict))
				return true;
			substr = ori_str;
			subres = ori_res;
		}
		if (wordBreak(s, index + 1, substr, subres, wordDict))
			return true;
		substr = ori_str;
		subres = ori_res;
		return false;
	}

	void proWordDict(unordered_set<string>& wordDict) {
		unordered_set<string> newList = wordDict;
		int size = wordDict.size();
		for (auto word : newList) {
			wordDict.erase(wordDict.find(word));
			string substr;
			bool subres = false;
			if (!wordBreak(word, 0, substr, subres, wordDict)) {
				wordDict.insert(word);
			}
		}
	}

public:
	//bool wordBreak(string s, unordered_set<string>& wordDict) {
	//	proWordDict(wordDict);
	//	string substr;
	//	bool subres = false;
	//	return wordBreak(s, 0, substr, subres, wordDict);
	//}
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> result(s.length(), false);
		for (int i = 0; i < s.length(); ++i) {
			if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
				result[i] = true;
				continue;
			} else {
				for (int j = 0; j < i; ++j) {
					if (result[j] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end()) {
						result[i] = true;
						break;
					}
				}
			}
		}
		return result[s.size() - 1];
	}
};

void test() {
	//unordered_set<string> wordDict = {"leet", "code"};
	//unordered_set<string> wordDict = { "aa" };
	//string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	//unordered_set<string> wordDict = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	//string str = "bacd";
	//unordered_set<string> wordDict = { "b","ba","cd" };
	string str = "abcde";
	unordered_set<string> wordDict = { "a", "bc", "def" };
	Solution s;
	cout << s.wordBreak(str, wordDict);
}