#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string s;
		//param limit
		if (n <= 0 || n > 9) {
			return s;
		}
		// fast get fact
		vector<int> fact(10, 1);
		for (int i = 2; i < n; ++i) {
			fact[i] = i * fact[i - 1];
		}
		//init
		vector<int> nums;
		for (int i = 0; i < 10; ++i) {
			nums.push_back(i);
		}
		//product result;
		for (int i = 1; i <= n; ++i) {
			int numIndex = (k - 1) / fact[n - i];
			k = (k - 1) % fact[n - i] + 1;
			s += '0' + nums[numIndex + 1];
			nums.erase(nums.begin() + numIndex + 1);
		}
		return s;
	}
};

void test() {
	vector<int> fact(10, 1);
	for (int i = 2; i < 10; ++i) {
		fact[i] = i * fact[i - 1];
	}
	//for (auto ele : fact) {
	//	cout << ele << endl;
	//}
	Solution s;
	for (int i = 1; i <= fact[4]; i++) {
		cout << s.getPermutation(4,i);
		cout << endl;
	}
}