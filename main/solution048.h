#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	void swampRUtoLD(vector<vector<int>>& matrix) {
		int temp;
		int n = matrix.size();
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
	}
	void swampLtoR(vector<vector<int>>& matrix) {
		int temp;
		int n = matrix.size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n / 2; ++j) {
				temp = matrix[i][j];
				matrix[i][j] = matrix[i][n - j - 1];
				matrix[i][n - j - 1] = temp;
			}
		}
	}
public:
	void rotate(vector<vector<int>>& matrix) {
		swampRUtoLD(matrix);
		swampLtoR(matrix);
	}
};

void test() {
	vector<vector<int>> matrix = { 
		{10,20,30,40},
		{50,60,70,80},
		{90,10,11,12},
		{13,14,15,16} 
	};
	for (auto row : matrix) {
		for (auto ele : row) {
			cout << ele << ' ';
		}
		cout << endl;
	}

	cout << " after swampLtoR .." << endl;
	(new Solution)->rotate(matrix);


	for (auto row : matrix) {
		for (auto ele : row) {
			cout << ele << ' ';
		}
		cout << endl;
	}


}