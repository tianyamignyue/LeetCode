#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int total = 1;
		int length = nums.size();
		while (length > 1)
			total *= length--;
		vector<vector<int>> result;
		for (int i = 0; i < total; ++i) {
			result.push_back(nums);
			next_permutation(nums.begin(), nums.end());
		}
		return result;
	}
};

void test() {
	vector<int> candidates = {2,2,3,3};
	vector<vector<int>> result;
	/*
	result = (new Solution)->permute(candidates);
	int i = 1;
	for (auto combination : result) {
		cout << i++ << " : ";
		for (auto ele : combination) {
			cout << ele << ' ';
		}
		cout << endl;
	}
	*/
	for (auto ele : candidates) {
		cout << ele << ' ';
	}
	cout << endl;
	next_permutation(candidates.begin(), candidates.end());
	for (auto ele : candidates) {
		cout << ele << ' ';
	}
	cout << endl;

}