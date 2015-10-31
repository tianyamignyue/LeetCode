#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unsigned find = 1;
		auto i = nums.begin();
		int m = *i;
		for (++i; i != nums.end(); ++i) {
			if (*i == m)
				++find;
			else {
				--find;
				if (find == 0) {
					m = *i;
					++find;
				}
			}
		}
		return m;
	}
};
int main()
{
	int v1[] = { 3,2,3,2,1,2,1,1,1,1,1,1,1,2,2,2 };
	vector<int> v(begin(v1), end(v1));
	Solution s;
	cout << s.majorityElement(v);
	return 0;
}