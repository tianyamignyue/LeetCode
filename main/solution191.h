#pragma once
#include <iostream>
#include <stdint.h>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		char res = 0;
		while (n) {
			res += n & 0x00000001;
			n = n >> 1;
		}
		return res;
	}
};

int main()
{
	cout << (new Solution)->hammingWeight(11);
	return 0;
}