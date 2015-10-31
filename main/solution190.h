#pragma once
#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t left = 0x80000000;
		uint32_t right = 0x00000001;
		while (left > right) {
			if ((bool)(n & left) != (bool)(n & right)) {
				n ^= (left | right);
			}
			left >>= 1;
			right <<= 1;
		}
		return n;
	}
};

int main()
{
	Solution s;
	cout << dec << (uint32_t)s.reverseBits(43261596);
	return 0;
}