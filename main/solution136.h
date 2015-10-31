#pragma once
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
	map<int, char> mapList;
	//遍历
	for (int i = 0; i < nums.size(); i++) {
		map<int, char>::iterator it;
		it = mapList.find(nums[i]);
		if (it == mapList.end())
			mapList[nums[i]] = 1;
		else
			mapList[nums[i]] = 2;
	}
	//找到结果
	for (map<int, char>::iterator i = mapList.begin(); i != mapList.end(); i++) {
		if (i->second == 1)
			return i->first;
	}
	return 0;
}
int singleNumberGood(vector<int>& nums) {
	vector<int>::iterator i = nums.begin();
	int res = *i;
	for (i++; i != nums.end(); i++) {
		res ^= *i;
	}
	return res;
}


int main()
{
	vector<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(6);
	list.push_back(5);
	list.push_back(4);
	list.push_back(3);
	list.push_back(2);
	list.push_back(1);
	cout << singleNumberGood(list);
	return 0;
}