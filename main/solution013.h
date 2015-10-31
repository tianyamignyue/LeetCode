#pragma once
#include <iostream>

using namespace std;

class Solution013 {
public:
	int romanValue(char c) {
		char roman[8] = "IVXLCDM";
		int value[8] = { 1,5,10,50,100,500,1000,0 };
		for (int i = 0; i < 8; i++) {
			if (c == roman[i])
				return value[i];
		}
		return 0;
	}
	int romanToInt(string s) {
		int res = 0;
		int oldv = 1000, newv = 0;
		for (int i = 0; i < s.length(); i++) {
			newv = romanValue(s[i]);
			res += newv;
			if (newv > oldv) {
				res -= oldv * 2;
			}
			oldv = newv;
		}
		return res;
	}
};

int main013()
{
	cout << "MMMCMXCIX" << "--" << (new Solution013)->romanToInt("MMMCMXCIX") << endl;
	return 0;
}