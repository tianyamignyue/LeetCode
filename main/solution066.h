#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int i = digits.size() - 1;
		for (; i >= 0; i--) {
			digits[i] = (digits[i] + 1) % 10;
			if (digits[i] != 0)
				break;
		}
		if (i < 0) {
			digits[0] = 1;
			digits.push_back(0);
		}
		return digits;
	}
};

int main()
{
	return 0;
}