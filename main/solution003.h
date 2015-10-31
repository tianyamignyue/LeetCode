#pragma once
#include <iostream>
#include <map>
using namespace std;

class Solution003 {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> chars;
		auto start = s.begin();
		auto end = s.begin();
		int max_length = 0;
		for (; end != s.end(); ++end) {
			auto it = chars.find(*end);
			if (it != chars.end()) {
				auto temp = (s.begin() + it->second + 1);
				while (start != temp) {
					auto f = chars.find(*start);
					if (f != chars.end())
						chars.erase(f);
					++start;
				}
				chars.insert(pair<char, int>(*end, end - s.begin()));
			}
			else {
				max_length = end - start + 1 > max_length ? end - start + 1 : max_length;
				chars.insert(pair<char, int>(*end, end - s.begin()));
			}
		}
		return max_length;
	}
};