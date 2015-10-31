#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/*
	void quickSort(vector<int>& nums, int start, int end){
	int flag = nums[start], temp, oriStart = start;
	while(start < end){
	if(nums[start] > flag){
	temp = nums[end];
	nums[end--] = nums[start];
	nums[start] = temp;
	} else {
	start++;
	}
	}
	nums[oriStart] = nums[start-1];
	nums[start-1] = flag;
	if(oriStart < start-3)
	quickSort(nums, oriStart, start - 2);
	if( start < end - 1)
	quickSort(nums, start, end);
	}*/
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < (int)nums.size() - 1; i++) {
			if (nums[i] == nums[i + 1])
				return true;
		}
		return false;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(5);
	nums.push_back(9);
	nums.push_back(6);
	nums.push_back(3);
	nums.push_back(8);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(0);
	cout << (new Solution)->containsDuplicate(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	return 0;
}