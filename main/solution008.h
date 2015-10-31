#pragma once
/*
Requirements for atoi:

The function first discards as many whitespace characters as necessary
until the first non-whitespace character is found. Then, starting from
this character, takes an optional initial plus or minus sign followed by
as many numerical digits as possible, and interprets them as a numerical
value.

The string can contain additional characters after those that form the
integral number, which are ignored and have no effect on the behavior
of this function.

If the first sequence of non-whitespace characters in str is not a valid
integral number, or if no such sequence exists because either str is
empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If
the correct value is out of the range of representable values, INT_MAX
(2147483647) or INT_MIN (-2147483648) is returned.

*/


#include <iostream>
#include <math.h>
using namespace std;

class Solution008 {
public:
	int myAtoi(string str) {
		int i = 0, len = str.length();
		long long res = 0;
		bool start = false, neg = false, first = false;
		char c;
		//not start
		while (i < len) {
			c = str[i];
			if (c == ' ' || c == '\t' || c == '\n') {
				i++;
			}
			else
				break;
		}

		if (c == '-') {
			neg = true;
			i++;
		}
		else if (c == '+') {
			i++;
		}
		//started
		while (i < len && (c = str[i++]) >= '0' && c <= '9') {
			res = res * 10 + (c - '0');
			if (res > int(0x7fffffff)) {
				return neg ? int(0x80000000) : int(0x7fffffff);
			}
			/*
			res = res * 10 + (c - '0');
			if(!neg){
			if(res < 0){
			res = int(0x7fffffff);
			break;
			}
			} else {
			if((res != 0) && res - 1 < 0){
			return int(0x80000000);
			}
			}*/
		}
		return neg ? 0 - res : res;
	}
};

int main008()
{
	cout << atoi("    10522545459") << ' ' << (new Solution008)->myAtoi("    10522545459") << endl;			//123
	return 0;
}