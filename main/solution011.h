#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution011 {
public:
	int maxArea(vector<int>& height) {
		int res = 0;
		int *area = new int[20];
		for (int i = 0; i < height.size(); ++i) {

		}
		return res;
	}
};

int main011()
{
	vector<vector<int>> mat;
	vector<int> row;
	/*
	for (int i = 0; i < 10; i++) {
	mat.push_back(row);
	}
	for (int i = 0; i < 10; i++) {
	for (int j = 0; j < i; j++) {
	mat[i].push_back(i + j);
	}
	}

	for (int i = 0; i < 10; i++) {
	for (int j = 0; j < i; j++) {
	cout << mat[i][j] << ' ';
	}
	cout << endl;
	}*/
	row = { 1,4,1,5,9,2,6 };
	cout << (new Solution)->maxArea(row);
	return 0;
}