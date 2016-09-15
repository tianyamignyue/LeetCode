#pragma once
//210. Course Schedule II
//https ://leetcode.com/problems/course-schedule-ii/

#include "leetCodeHead.h"

class Solution {
	typedef vector<unordered_set<int>> Graph;
	void dfs(Graph& g, int start, vector<int>& visited, vector<int>& order, int& current_label) {
		visited[start] = 1;
		for (auto end : g[start]) {
			if (!visited[end]) {
				dfs(g, end, visited, order, current_label);
			}
		}
		order[current_label] = start;
		--current_label;
	}
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		Graph graph(numCourses);
		for (auto edge : prerequisites) {
			graph[edge.second].insert(edge.first);
		}
		vector<int> visited(numCourses, 0);
		vector<int> order(numCourses, 0);

		//dfs-loop
		int current_label = numCourses - 1;
		for (int v = 0; v < numCourses; ++v) {
			if (!visited[v]) {
				dfs(graph, v, visited, order, current_label);
			}
		}

		//check if is a topological sort

		vector<int> cvisit(numCourses, 0);
		for (int i = 0; i < numCourses; ++i) {
			int v = order[i];
			cvisit[v] = 1;
			for (auto next : graph[v]) {
				if (cvisit[next]) {
					order.clear();
					return order;
				}
			}
		}
		return order;
	}
};

void test(){
	vector<pair<int, int>> pre = {};
	int num = 2;
	Solution s;
	printv(s.findOrder(num, pre));
}
