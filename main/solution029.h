#pragma once
class Solution029 {
public:
	int divide(int dividend, int divisor) {
		static const int MAX_INT = 0x7fffffff;
		//overflow
		if (!divisor)
			return MAX_INT;
		if (divisor == -1 && dividend == MAX_INT + 1)
			return MAX_INT;
		unsigned negative = 0;
		unsigned udividend, udivisor;
		udividend = dividend < 0 ? 0 - dividend : dividend;
		udivisor = divisor < 0 ? 0 - divisor : divisor;
		negative = dividend < 0 ? 1 : 0;
		negative = divisor < 0 ? !negative : negative;

		if (udivisor > udividend || !udividend)
			return 0;


		unsigned multi = 0;
		unsigned halfDividend = udividend >> 1;
		int res = 0;
		while (udivisor <= halfDividend) {
			udivisor <<= 1;
			++multi;
		}

		while (udividend >= udivisor) {
			udividend -= udivisor;
			res += (1 << multi);
			if (!multi)
				break;
			while (udividend < udivisor && multi) {
				udivisor >>= 1;
				--multi;
			}
		}
		return negative ? 0 - res : res;
	}
};