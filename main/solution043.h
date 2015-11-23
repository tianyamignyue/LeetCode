#pragma once

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string result(num1.length()+num2.length(), '0');
		for (int i = (num1.size()-1); i >= 0; --i) {
			int a = num1[i] - '0';
			if (a == 0)
				continue;
			int c = 0;
			int j;
			for (j = num2.size() - 1; j >= 0; --j) {
				int b = num2[j] - '0';
				int k = result[i + j + 1] - '0';
				int t = a * b + k;
				c = t / 10;
				t %= 10;
				result[i + j + 1] = t + '0';
				int m = 0;
				while (c) {
					t = result[i + j + m] - '0';
					c += t;
					result[i + j + m] = c % 10 + '0';
					c /= 10;
					--m;
				}
			}
		}
		auto z = result.begin();
		while (z != result.end() - 1 && *z == '0')
			++z;
		result.erase(result.begin(), z);
		return result;
	}
};

void test() {
	cout << (new Solution)->multiply("1234567890","9876543210");
}