#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Solution {
	int searchInCol(vector<vector<int>>& matrix, int target, int start, int end) {
		if (end - start < 1) {
			return start;
		}
		int mid = (start + end) / 2;
		if (matrix[mid][0] < target && (mid + 1 < matrix.size() ? matrix[mid + 1][0] > target : true)) {
			return mid;
		}
		else if (matrix[mid][0] == target) {
			return mid;
		}
		else if (matrix[mid][0] < target) {
			return searchInCol(matrix, target, mid + 1, end);
		}
		else {
			return searchInCol(matrix, target, start, mid);
		}
	}
	bool searchInRow(vector<vector<int>>& matrix, int target, int row, int start, int end) {
		if (end - start < 1) {
			return false;
		}
		int mid = (start + end) / 2;
		if (matrix[row][mid] == target) {
			return true;
		}
		else if (matrix[row][mid] < target) {
			return searchInRow(matrix, target, row, mid + 1, end);
		}
		else {
			return searchInRow(matrix, target, row, start, mid);
		}
	}
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size();
		int row = searchInCol(matrix, target, 0, m);
		return searchInRow(matrix, target, row, 0, n);
	}
};

void test() {
	vector<vector<int>> matrix = { {1,3} };
	Solution s;
	cout << s.searchMatrix(matrix, 1);
}