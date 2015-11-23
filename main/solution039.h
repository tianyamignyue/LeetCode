#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
	void find2(vector<int>& candidates, int sum, int target, int index,
		vector<int> combination, vector<vector<int>>& result) {
		for (++index; index < candidates.size(); ++index) {
			int temp;
			temp = sum + candidates[index];
			auto subcom = combination;
			subcom.push_back(candidates[index]);
			if (temp < target) {
				find2(candidates, temp, target, index, subcom, result);
				//candidates.erase(candidates.end() - 1);
			}
			else if (temp == target) {
				result.push_back(subcom);
				break;
			}
			else {
				break;
			}
		}
		return;
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		if (candidates.size() == 0)
			return result;
		vector<int> combination;
		sort(candidates.begin(), candidates.end());
		find2(candidates, 0, target, -1, combination, result);
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}

	void find(vector<int>& candidates, int sum, int target, int index,
		vector<int> combination, vector<vector<int>>& result) {
		for (index; index < candidates.size(); ++index) {
			int temp;
			temp = sum + candidates[index];
			auto subcom = combination;
			subcom.push_back(candidates[index]);
			if (temp < target) {
				find(candidates, temp, target, index, subcom, result);
				//candidates.erase(candidates.end() - 1);
			}
			else if (temp == target) {
				result.push_back(subcom);
				break;
			} else {
				break;
			}
		}
		return ;
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		if (candidates.size() == 0)
			return result;
		vector<int> combination;
		find(candidates, 0, target, 0, combination, result);
		return result;
	}
};

void test() {
	vector<int> candidates = {10,1,2,7,6,1,5};
	vector<vector<int>> result;

	result = (new Solution)->combinationSum2(candidates, 8);

	for (auto combination : result) {
		for (auto ele : combination) {
			cout << ele << ' ';
		}
		cout << endl;
	}


}/*
1 1 1 1 1 1 1 1
1 1 1 1 1 1 2
1 1 1 1 1 3
1 1 1 1 2 2
1 1 1 1 4
1 1 1 2 3
1 1 1 5
1 1 2 2 2
1 1 2 4
1 1 3 3
1 1 6
1 2 2 3
1 2 5
1 3 4
1 7
2 2 2 2
2 2 4
2 3 3
2 6
3 5
4 4
8
[1,1,1,1,1,1,1,1]
[1,1,1,1,1,1,2]
[1,1,1,1,1,3]
[1,1,1,1,2,2]
[1,1,1,1,4]
[1,1,1,2,3]
[1,1,1,5]
[1,1,2,2,2]
[1,1,2,4]
[1,1,3,3]
[1,1,6]
[1,2,2,3]
[1,2,5]
[1,3,4]
[1,7]
[2,2,2,2]
[2,2,4]
[2,3,3]
[2,6]
[3,5]
[4,4]
[8]


*/