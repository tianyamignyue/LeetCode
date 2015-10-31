#pragma once
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string res;
		int sum = 0;
		int temp;
		int i = a.length() - 1, j = b.length() - 1;
		while (i >= 0 && j >= 0) {
			temp = a[i--] + b[j--] - 2 * '0' + sum;
			sum = temp / 2;
			temp %= 2;
			if (temp == 0)
				res += '0';
			else
				res += '1';
		}
		while (i >= 0) {
			temp = a[i--] - '0' + sum;
			sum = temp / 2;
			temp %= 2;
			if (temp == 0)
				res += '0';
			else
				res += '1';
		}
		while (j >= 0) {
			temp = b[j--] - '0' + sum;
			sum = temp / 2;
			temp %= 2;
			if (temp == 0)
				res += '0';
			else
				res += '1';
		}
		if (sum == 1)
			res += '1';
		for (int i = 0; i < res.length() / 2; i++) {
			temp = res[res.length() - i - 1];
			res[res.length() - i - 1] = res[i];
			res[i] = temp;
		}
		return res;

	}
};

int main()
{
	Solution s;
	cout << s.addBinary("100", "11111000");
	return 0;
}