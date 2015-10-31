#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "windows.h"
using namespace std;

class Solution {
	/*vector<vector<int>> res;
	int cval = 0;
	vector<int> ans1;
	vector<int>::const_iterator begin, end;
	int aim;*/
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		int cval = 0;
		vector<int> ans1;
		vector<int>::const_iterator begin, end;
		int aim;
		if (nums.size() < 3)
			return res;
		sort(nums.begin(), nums.end());
		auto i = nums.cbegin();
		while (i != (nums.cend() - 2)) {
			begin = i + 1, end = nums.cend();
			--end;
			aim = 0 - *i;
			while (begin < end) {
				int sum = (*begin) + (*end);
				if (sum < aim) {
					++begin;
					while (begin < end && (*begin) == (*(begin - 1)))
						++begin;
				}
				else if (sum > aim) {
					--end;
					while (begin < end && (*end) == (*(end + 1)))
						--end;
				}
				else {
					ans1.resize(3);
					ans1[0] = (*i);
					ans1[1] = (*begin);
					ans1[2] = (*end);
					if (res.size() == 0 || ans1 != res.back())
						res.push_back(ans1);
					++begin;
					while (begin < end && (*begin) == (*(begin - 1)))
						++begin;
					--end;
					while (begin < end && (*end) == (*(end + 1)))
						--end;
				}
			}
			++i;
			while (i != (nums.cend() - 2) && *i == *(i - 1))
				++i;
		}
		return res;
	}

	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3)
			return 0;
		int retSum;
		unsigned dist = -1;
		vector<int>::const_iterator begin, end;
		sort(nums.begin(), nums.end());
		auto i = nums.cbegin();
		while (i != (nums.cend() - 2)) {
			begin = i + 1, end = nums.cend();
			--end;
			while (begin < end) {
				int sum = (*begin) + (*end) + (*i);
				int newd = (sum < target) ? target - sum : sum - target;
				if (newd < dist) {
					retSum = sum;
					dist = newd;
				}
				if (sum < target) {
					++begin;
					while (begin < end && (*begin) == (*(begin - 1)))
						++begin;
				}
				else if (sum > target) {
					--end;
					while (begin < end && (*end) == (*(end + 1)))
						--end;
				}
				else
					return sum;
			}
			++i;
			while (i != (nums.cend() - 2) && *i == *(i - 1))
				++i;
		}
		return retSum;
	}
};
int main()
{
	/*
	vector<int> test = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<vector<int>> result;
	long start = GetTickCount();
	int i = 0;
	Solution s;
	while (i++ < 99) {
	(new Solution)->threeSum(test);
	}
	result = (new Solution)->threeSum(test);
	cout << "-------" << (GetTickCount() - start) / 100.0 << "-------" << endl;
	for (int i = 0; i < result.size(); ++i) {
	vector<int> t = result[i];
	cout << "{" << t[0] << ',' << t[1] << ',' << t[2] << "}";
	cout << "--";
	}
	cout << (unsigned)-1 << endl;*/
	vector<int> test = { 0,0,0 };
	cout << (new Solution)->threeSumClosest(test, 1);
	return 0;
}