#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	vector<int> gotMoney;
	bool useNew;
public:
	vector<int> rob(vector<int>& nums) {
		if (nums.size() == 0) {
			//return 0;
		}
		else if (nums.size() == 1) {
			//return nums[0];
		}
		gotMoney.push_back(nums[0]);
		if (nums[1] > nums[0]) {
			useNew = true;
			gotMoney.push_back(nums[1]);
		}
		else {
			useNew = false;
			gotMoney.push_back(nums[0]);
		}
		for (int i = 2; i < nums.size(); ++i) {
			if (!useNew) {
				useNew = true;
				gotMoney.push_back(gotMoney[i - 1] + nums[i]);
			}
			else if (gotMoney[i - 2] + nums[i] > gotMoney[i - 1]) {
				gotMoney.push_back(gotMoney[i - 2] + nums[i]);
			}
			else {
				useNew = false;
				gotMoney.push_back(gotMoney[i - 1]);
			}
		}
		return gotMoney;
	}
};

int main()
{
	int hv[] = { 1,5,9,2,6,5,3,5,8,9,7,9 };
	vector<int> house(begin(hv), end(hv));
	vector<int> money;
	Solution s;
	money = s.rob(house);
	for (int i = 0; i < house.size(); i++) {
		cout << house[i] << " " << money[i] << endl;
	}
	return 0;
}