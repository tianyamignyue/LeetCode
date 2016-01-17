#pragma once

//133. Clone Graph
//https ://leetcode.com/problems/clone-graph/

#include "leetCodeHead.h"

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr)
			return nullptr;
		UndirectedGraphNode* firstNode = nullptr;
		unordered_set<UndirectedGraphNode*> unvisit;
		unordered_set<int> visited;
		unordered_map<int, UndirectedGraphNode*> mapt;
		unvisit.insert(node);
		while (!unvisit.empty()) {
			UndirectedGraphNode *pn = *unvisit.begin();
			unvisit.erase(unvisit.begin());
			if (visited.find(pn->label) != visited.end())
				continue;
			visited.insert(pn->label);
			auto find = mapt.find(pn->label);
			if (find == mapt.end()) {
				//node
				UndirectedGraphNode* newNode = new UndirectedGraphNode(pn->label);
				mapt.insert(pair<int, UndirectedGraphNode*>(pn->label, newNode));
				if (firstNode == nullptr)
					firstNode = newNode;
				//side
				for (auto next : pn->neighbors) {
					auto find = mapt.find(next->label);
					if (find == mapt.end()) {
						UndirectedGraphNode* newNode2 = new UndirectedGraphNode(next->label);
						mapt.insert(pair<int, UndirectedGraphNode*>(next->label, newNode2));
						newNode->neighbors.push_back(newNode2);
					}
					else {
						newNode->neighbors.push_back(find->second);
					}
					if(visited.find(next->label) == visited.end())
						unvisit.insert(next);
				}
			}
			else {
				for (auto next : pn->neighbors) {
					auto find2 = mapt.find(next->label);
					if (find2 == mapt.end()) {
						UndirectedGraphNode* newNode2 = new UndirectedGraphNode(next->label);
						mapt.insert(pair<int, UndirectedGraphNode*>(next->label, newNode2));
						find->second->neighbors.push_back(newNode2);
					}
					else {
						find->second->neighbors.push_back(find2->second);
					}
					if (visited.find(next->label) == visited.end())
						unvisit.insert(next);
				}
			}
		}
		return firstNode;
	}
};

void test() {
	//{0, 1#1, 2#2, 2}
	
	UndirectedGraphNode * n0 = new UndirectedGraphNode(0);
	UndirectedGraphNode * n1 = new UndirectedGraphNode(1);
	UndirectedGraphNode * n2 = new UndirectedGraphNode(2);

	n0->neighbors.push_back(n1);
	n1->neighbors.push_back(n2);
	n2->neighbors.push_back(n2);
	Solution s;
	UndirectedGraphNode * g2 = s.cloneGraph(n0);
}