#pragma once
#include <iostream>
#include <string>
using namespace std;

class Solution006 {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		string res;
		int i = 1, j = 0;
		int len = s.length();
		int step1, step2;
		//first line
		step1 = 2 * numRows - 2;
		while (j < len) {
			res.push_back(s.at(j));
			j += step1;
		}
		//other line
		while (i < numRows - 1) {
			step1 = 2 * (numRows - i - 1);
			step2 = 2 * i;
			j = i;
			while (j < len) {
				res.push_back(s.at(j));
				j += step1;
				if (j >= len)
					break;
				res.push_back(s.at(j));
				j += step2;
			}
			i++;
		}
		//last line
		step2 = 2 * numRows - 2;
		j = numRows - 1;
		while (j < len) {
			res.push_back(s.at(j));
			j += step2;
		}

		return res;
	}
};

int main006()
{
	cout << (new Solution006)->convert("123456789abcde", 2);
	return 0;
}