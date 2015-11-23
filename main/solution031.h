#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Solution {
	void convert(vector<int>::iterator begin, vector<int>::iterator end) {
		--end;
		while (begin < end) {
			*begin ^= *end;
			*end ^= *begin;
			*begin ^= *end;
			++begin;
			--end;
		}
	}
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1)
			return;
		auto first = nums.rbegin();
		auto second = first + 1;
		while (second != nums.rend()) {
			if (*first > *second) {
				//find a num bigger than *second
				auto p = nums.rbegin();
				while (p < second) {
					if (*p > *second)
						break;
					++p;
				}
				//chang the max number
				*p ^= *second;
				*second ^= *p;
				*p ^= *second;
				//convert left nums;
				convert(--first.base(), nums.end());
				return;
			}
			++first;
			++second;
		}

		//it is a last permution
		convert(nums.begin(), nums.end());
	}
};

void test() {
	Solution s;
	vector<int> v = { 2,2,3,3 };
	for (auto i : v) {
		cout << i << ' ';
	}
	cout << endl;
	s.nextPermutation(v);
	for (auto i : v) {
		cout << i << ' ';
	}
	cout << endl;
}