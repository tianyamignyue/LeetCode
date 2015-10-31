#pragma once
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Solution {
public:
	int titleToNumber(string s) {
		int res = 0, i = 0;
		int len = s.length();
		while (i < len) {
			res += (s.at(i) - 'A' + 1) * pow(26.0, len - i - 1);
			i++;
		}
		return res;
	}
};
int main()
{
	cout << (new Solution)->titleToNumber("AA");
	return 0;
}