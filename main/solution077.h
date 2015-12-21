#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {

	vector<vector<int>> result;
public:
	vector<vector<int>> combine1(int n, int k) {
		//like man think,in this meathod ,control flue is too complex!!!
		//give up it !!!
		vector<vector<int>> result;
		vector<int> subCombine(k, 0);
		if (n <= 0 || k <= 0 || k > n) {
			return result;
		}

		//init index[]
		for (int i = 0; i < k; ++i) {
			subCombine[i] = i + 1;
		}
		//first one like 1,2,3

		result.push_back(subCombine);
		int passNum = k - 2;
		int j;
		while (subCombine[0] <= n - k + 1) {
			//create combine one pass
			while (subCombine[k - 1] < n) {
				++subCombine[k - 1];
				result.push_back(subCombine);
			}
			//next pass
			j = passNum;
			++subCombine[j++];
			while (j < k) {
				subCombine[j] = subCombine[j - 1] + 1;
				++j;
			}
			if (subCombine[k - 1] > n) {
				passNum = passNum == 0 ? k - 2 : passNum - 1;
				continue;
			}
			result.push_back(subCombine);

		}
		return result;
	}

	void createCombine(int level, int fatherVal, int n, int k, vector<int> &combine, vector<vector<int>> &result) {
		if (level == k) {
			result.push_back(combine);
			return;
		}
		for (int i = fatherVal + 1; i < level + n - k + 2; ++i) {
			combine[level] = i;
			createCombine(level + 1, i, n, k, combine, result);
		}
	}

	void combine(int n, int k, vector<vector<int>> &result) {
		vector<int> combine(k, 0);
		createCombine(0, 0, n, k, combine, result);
	}


	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> ss;
		result.push_back(ss);
		for (int i = 1; i < nums.size() + 1; ++i) {
			vector<vector<int>> indexs;
			combine(nums.size(), i, indexs);
			for (auto indexArray : indexs) {
				for (auto index : indexArray) {
					ss.push_back(nums[index - 1]);
				}
				result.push_back(ss);
				ss.clear();
			}
		}
		return result;
	}
};

void test(void) {
	vector<vector<int>> result;
	vector<int> nums = {0};
	Solution s;
	s.subsets(nums);
	int i = 1;
	for (auto row : result) {
		cout << i++ << ":\t";
		for (auto ele : row) {
			cout << ele << " ";
		}
		cout << endl;
	}
}