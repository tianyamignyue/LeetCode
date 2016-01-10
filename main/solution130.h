#pragma once

#include "leetCodeHead.h"

class Solution {
	void saveBFS(vector<string>& board, vector<vector<bool>>& survive, int m, int n, list<pair<int,int>>& vlist) {
		int i, j;
		while (!vlist.empty()) {
			pair<int, int> visit = vlist.front();
			vlist.pop_front();
			i = visit.first;
			j = visit.second;
			survive[i][j] = true;
			if (i - 1 >= 0 && board[i - 1][j] == 'O' && !survive[i - 1][j]) {
				vlist.push_back(pair<int, int>(i - 1, j));
			}
			if (i + 1 < m && board[i + 1][j] == 'O' && !survive[i + 1][j]) {
				vlist.push_back(pair<int, int>(i + 1, j));
			}
			if (j - 1 >= 0 && board[i][j - 1] == 'O' && !survive[i][j - 1]) {
				vlist.push_back(pair<int, int>(i, j - 1));
			}
			if (j + 1 < n && board[i][j + 1] == 'O' && !survive[i][j + 1]) {
				vlist.push_back(pair<int, int>(i, j + 1));
			}
		}
	}
public:
	void solve(vector<string>& board) {
		int rs = board.size();
		if (!rs)
			return;
		int cs = board[0].size();
		if (!cs)
			return;
		vector<bool> row(cs,false);
		vector<vector<bool>> survive;
		list<pair<int, int>> vlist;
		for (int i = 0; i < rs; ++i) {
			survive.push_back(row);
		}
		for (int i = 0; i < rs; ++i) {
			if (i == 0 || i == rs - 1) {
				for (int j = 0; j < cs; ++j) {
					if (board[i][j] == 'O') {
						vlist.push_back(pair<int,int>(i, j));
					}
				}
			}
			else {
				if (i == 3)
					i = i;
				if (board[i][0] == 'O') {
					vlist.push_back(pair<int, int>(i, 0));
				}
				if (board[i][cs - 1] == 'O') {
					vlist.push_back(pair<int, int>(i, cs - 1));
				}
			}
		}

		saveBFS(board, survive, rs, cs, vlist);


		//kill dead 'o'
		for (int i = 0; i < rs; ++i) {
			for (int j = 0; j < cs; ++j) {
				if (board[i][j] == 'O' && !survive[i][j]) {
					board[i][j] = 'X';
				}
			}
		}
	}
};

void test() {
	//vector<vector<char>> input = { { 'O','X','X','O','X' },{ 'X','O','O','X','O' },{ 'X','O','X','O','X' },{ 'O','X','O','O','O' },{ 'X','X','O','X','O' }};
	//
	vector<string> input = { "XOOOOOOOOOOOOOOOOOOO","OXOOOOXOOOOOOOOOOOXX","OOOOOOOOXOOOOOOOOOOX","OOXOOOOOOOOOOOOOOOXO","OOOOOXOOOOXOOOOOXOOX","XOOOXOOOOOXOXOXOXOXO","OOOOXOOXOOOOOXOOXOOO","XOOOXXXOXOOOOXXOXOOO","OOOOOXXXXOOOOXOOXOOO","XOOOOXOOOOOOXXOOXOOX","OOOOOOOOOOXOOXOOOXOX","OOOOXOXOOXXOOOOOXOOO","XXOOOOOXOOOOOOOOOOOO","OXOXOOOXOXOOOXOXOXOO","OOXOOOOOOOXOOOOOXOXO","XXOOOOOOOOXOXXOOOXOO","OOXOOOOOOOXOOXOXOXOO","OOOXOOOOOXXXOOXOOOXO","OOOOOOOOOOOOOOOOOOOO","XOOOOXOOOXXOOXOXOXOO"};
	Solution s;
	printvs(input);
	cout << "after solve..." << endl;
	s.solve(input);
	printvs(input);
}