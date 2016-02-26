#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>

#include <vector>
#include <list>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

static const int MIN_INT = 0x80000000;
static const int MAX_INT = 0x7fffffff;
static const int NO_VALUE = 0x12345678;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
* Definition for undirected graph.
*/
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

template <class TYPE>
void printv(const vector<TYPE> &vec) {
	for (auto ele : vec) {
		cout << ele << '\t';
	}
	cout << endl;
}

void printvs(const vector<string> &vec) {
	for (auto ele : vec) {
		cout << ele << endl;
	}
	cout << endl;
}

template <class TYPE>
void printvv(const vector<vector<TYPE>> &vec) {
	for (auto row : vec) {
		printv(row);
	}
}

ListNode* buildList(const vector<int> &nums) {
	ListNode *head(NULL), *p(NULL);
	if (!nums.empty()) {
		p = head = new ListNode(nums[0]);
	} else {
		return NULL;
	}
	for (unsigned i = 1; i < nums.size(); ++i) {
		p->next = new ListNode(nums[i]);
		p = p->next;
	}
	return head;
}


//use NO_VALUE ,there may be a bug in case that a value is NO_VALUE(0x12345678)
TreeNode* buildTree(const vector<int> &nums) {
	queue<TreeNode**> level;
	TreeNode *root = NULL;
	level.push(&root);
	for (auto ele : nums) {
		if (level.empty())
			break;
		TreeNode **node = level.front();
		level.pop();
		if (ele != NO_VALUE) {
			*node = new TreeNode(ele);
			level.push(&((*node)->left));
			level.push(&((*node)->right));
		}
	}
	return root;
}

void printWhiten(unsigned n) {
	if (n <= 0)
		return;
	while (n--) {
		cout << ' ';
	}
}

//返回一个二叉树的高度(层数)
unsigned getTreeHeight(TreeNode *root) {
	if (!root)
		return 0;
	return max(getTreeHeight(root->left), getTreeHeight(root->right)) + 1;
}

//在控制台中，打印一颗二叉树
void printTree(TreeNode* root, int maxNumWidth) {
	//cout << "     11"	<< endl;
	//cout << "   /     \\"	<< endl;
	//cout << "  22      33" << endl;
	//cout << " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\" << endl;
	//cout << "44 45 6 7 8 9 8 7 6 5 4 3 2 1" << endl;
	if (!root)
		return;
	list<TreeNode*> level;
	list<bool> isleft;
	level.push_back(root);
	isleft.push_back(false);
	int height = getTreeHeight(root);
	for (int i = 0; i < height; ++i) {
		int width = (1 << (height - 1 - i)) * (maxNumWidth + 1) - 1;
		if (i == height - 1)
			width = maxNumWidth;
		int total = level.size();
		//print the branch
		for (int nums = 0; i != 0 && nums < total; ++nums) {
			printWhiten((width - maxNumWidth) >> 1);
			TreeNode* node = level.front();
			bool left = isleft.front();
			level.pop_front();
			isleft.pop_front();
			if (!node) {
				printWhiten(maxNumWidth);
			}
			else {
				if(isleft.front())
					cout << setw(maxNumWidth) << '\\';
				else
					cout << setw(maxNumWidth) << '/';
			}
			if (i != height - 1)
				printWhiten(width - ((width - maxNumWidth) >> 1) - maxNumWidth + 1);
			else
				printWhiten(1);
			level.push_back(node);
			isleft.push_back(left);
		}
		cout << endl;


		for (int nums = 0; nums < total; ++nums) {
			printWhiten((width - maxNumWidth) >> 1);
			TreeNode* node = level.front();
			level.pop_front();
			isleft.pop_front();
			if (!node) {
				printWhiten(maxNumWidth);
				level.push_back(NULL);
				isleft.push_back(true);
				level.push_back(NULL);
				isleft.push_back(false);
			} else {
				cout <<setw(maxNumWidth)<< node->val;
				level.push_back(node->left);
				isleft.push_back(true);
				level.push_back(node->right);
				isleft.push_back(false);
			}
			if (i != height - 1)
				printWhiten(width - ((width - maxNumWidth)>>1) - maxNumWidth + 1);
			else
				printWhiten(1);
		}
		cout << endl;
	}
}

