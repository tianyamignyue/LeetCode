#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		int cval = 0;
		vector<int> ans1;
		vector<int>::const_iterator begin, end;
		int aim;
		if (nums.size() < 4)
			return res;
		sort(nums.begin(), nums.end());
		auto i = nums.cbegin();
		//four sum
		while (i <= (nums.cend() - 3)) {
			auto j = i + 1;
			//three sum
			while (j <= (nums.cend() - 2)) {
				//two sum
				begin = j + 1, end = nums.cend();
				--end;
				aim = target - *i - *j;
				while (begin < end) {
					int sum = (*begin) + (*end);
					if (sum < aim) {
						++begin;
					}
					else if (sum > aim) {
						--end;
					}
					else {
						ans1.resize(4);
						ans1[0] = (*i);
						ans1[1] = (*j);
						ans1[2] = (*begin);
						ans1[3] = (*end);
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
				++j;
				while (j != (nums.cend() - 2) && *j == *(j - 1))
					++j;
			}
			++i;
			while (i != (nums.cend() - 2) && *i == *(i - 1))
				++i;
		}
		return res;
	}
};
int main()
{
	vector<int> test = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> result;
	result = (new Solution)->fourSum(test, 0);
	for (int i = 0; i < result.size(); ++i) {
		vector<int> t = result[i];
		cout << "{" << t[0] << ',' << t[1] << ',' << t[2] << ',' << t[3] << "}";
		cout << "--";
	}
	return 0;
}

/*
*/