#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
	map<int, int> m;
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		for (auto i = nums.begin(); i != nums.end(); ++i) {
			auto iter = m.find(*i);
			if (iter != m.end()) {
				if (i - nums.begin() - iter->second <= k)
					return true;
				else
					m.erase(iter);
			}
			m.insert(pair<int, int>(*i, i - nums.begin()));

		}
		return false;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);
	/*nums.push_back(8);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(0);*/
	cout << (new Solution)->containsNearbyDuplicate(nums, 1);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	map<int, int> mp;
	mp.insert(pair<int, int>(1, 10));
	mp.insert(pair<int, int>(1, 100));
	//mp.erase();
	return 0;
}