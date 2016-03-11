#pragma once
//207. Course Schedule
//https ://leetcode.com/problems/course-schedule/

#include "leetCodeHead.h"

//topological sort from stanfold

class Solution {
	typedef vector<unordered_set<int>> Graph;
	void dfs(Graph& g, int start, vector<int>& visited, vector<int>& order, int& current_label) {
		visited[start] = 1;
		for (auto end : g[start]) {
			if (!visited[end]) {
				dfs(g, end, visited, order, current_label);
			}
		}
		order[start] = current_label;
		--current_label;
	}
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		Graph graph(numCourses);
		for (auto edge : prerequisites) {
			graph[edge.second].insert(edge.first);
		}
		vector<int> visited(numCourses, 0);
		vector<int> order(numCourses, 0);

		//dfs-loop
		int current_label = numCourses;
		for (int v = 0; v < numCourses; ++v) {
			if (!visited[v]) {
				dfs(graph, v, visited, order, current_label);
			}
		}

		//check if is a topological sort

		//1. reorder
		vector<int> topoSort(numCourses, 0);
		for (int v = 0; v < numCourses; ++v) {
			topoSort[order[v] - 1] = v;
		}
		//2. check
		vector<int> cvisit(numCourses, 0);
		for (int i = 0; i < numCourses; ++i) {
			int v = topoSort[i];
			cvisit[v] = 1;
			for (auto next : graph[v]) {
				if (cvisit[next]) {
					return false;
				}
			}
		}
		return true;
	}
};

void test() {
	int num = 3;
	vector<pair<int, int>> pre = { pair<int, int>(0,1),pair<int, int>(0,2),pair<int, int>(1,2)};

	Solution s;

	cout << endl << s.canFinish(num, pre);
}