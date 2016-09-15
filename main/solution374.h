#pragma once

#include "leetCodeHead.h"

int answer = 1702766719;


// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num) {
	int dif = answer - num;
	if (!dif) {
		return 0;
	} else if(dif > 0){
		return 1;
	} else {
		return -1;
	}
}

class Solution {
public:
	int guessNumber(int n) {
		int begin = 1, end = n;

		while (begin < end) {
			int mid = (begin + end) >> 1;
			int res = guess(mid);
			if (res == 0) {
				return mid;
			} else if (res == 1) {
				begin = mid + 1;
			} else {
				end = mid - 1;
			}
		}
		return begin;
	}
};

void test() {
	Solution s;
	cout << s.guessNumber(2126753390);
}