#pragma once
#include <iostream>

using namespace std;

class Solution007 {
public:
	int reverse(int x) {
		int res = 0;
		bool neg = false;
		char c;
		x < 0 ? neg = true, x = 0 - x : 0;
		while (x > 0) {
			c = x % 10;
			x /= 10;
			if (res >int(0x7fffffff) / 10) {
				res = 0;
				break;
			}
			res = (res * 10) + c;

		}
		return neg ? 0 - res : res;
	}
};

int main007()
{
	cout << (new Solution007)->reverse(1000);
	int a;
	a = 0x7fffffff;
	cout << a;


	return 0;
}