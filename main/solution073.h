#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return;
		int n = matrix[0].size();
		bool find = false;
		int savei, savej;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					if (find) {
						matrix[savei][j] = 0;
						matrix[i][savej] = 0;
					} else {
						find = true;
						savei = i;
						savej = j;
					}
				}
			}
		}
		if (find) {
			for (int i = 0; i < m; ++i) {
				if (matrix[i][savej] == 0 && i != savei) {
					for (int j = 0; j < n; ++j) {
						if(j != savej)
							matrix[i][j] = 0;
					}
				}
			}

			for (int j = 0; j < n; ++j) {
				if (matrix[savei][j] == 0 && j != savej) {
					for (int i = 0; i< m; ++i) {
						if(i != savei)
							matrix[i][j] = 0;
					}
				}
			}
			for (int i = 0; i< m; ++i) {
				matrix[i][savej] = 0;
			}
			for (int j = 0; j < n; ++j) {
				matrix[savei][j] = 0;
			}
		}
	}
};

void test() {
	vector<vector<int>> matrix = { {9,-6,-1,-2,5},{-1,3,2147483647,-4,0},{-3,-4,0,4,(int)-2147483648} };
	Solution s;
	s.setZeroes(matrix);
	int m = matrix.size();
	if (m == 0)
		return;
	int n = matrix[0].size();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}