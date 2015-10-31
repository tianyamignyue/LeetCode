#pragma once
#include <iostream>

using namespace std;

class Solution009 {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (x < 10)
			return true;
		int length = 1, rule = 10;
		while (x / rule / 10 != 0) {
			rule *= 10;
			++length;
		}
		length++;
		int n = length / 2, i = 1, step = 10, start, end;
		while (i <= n) {
			start = (x / rule) % 10;
			end = (x % step) / (step / 10);
			if (start == end) {
				i++;
				rule /= 10;
				step *= 10;
			}
			else {
				return false;
			}
		}
		return true;
	}
};

int main009()
{
	cout << (new Solution009)->isPalindrome(10022001);
	return 0;
}