#pragma once
#include <iostream>

using namespace std;

class TrieNode {
public:
	const  unsigned MAXCHARNUM = 26;
	unsigned count;
	TrieNode *next[26];
public:
	// Initialize your data structure here.
	TrieNode() {
		count = 0;
		for (auto& p : next) {
			p = NULL;
		}
	}
};

class Trie {
private:
	TrieNode* root;
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode *p = root;
		for (auto c : word) {
			if (p->next[c - 'a'] == NULL) {
				p->next[c - 'a'] = new TrieNode();
			}
			p = p->next[c - 'a'];
		}
		++(p->count);
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode *p = root;
		for (auto c : word) {
			if (p->next[c - 'a'] == NULL) {
				return false;
			}
			p = p->next[c - 'a'];
		}
		return p->count;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode *p = root;
		for (auto c : prefix) {
			if (p->next[c - 'a'] == NULL) {
				return false;
			}
			p = p->next[c - 'a'];
		}
		return true;
	}
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


class Node {
public:
	const static unsigned MAXCHARNUM = 26;
	unsigned count;
	Node * next[MAXCHARNUM];

public:
	Node() {
		count = 0;
		for (auto &p : next) {
			p = NULL;
		}
	}
};

class WordDictionary {
	Node * root;
	bool search(Node *subRoot, string word) {
		Node *p = subRoot;
		for (auto i = word.begin(); i != word.end() && p != NULL; ++i) {
			if (*i != '.') {
				if (p->next[*i - 'a'] == NULL) {
					return false;
				}
				p = p->next[*i - 'a'];
			}
			else {
				for (int j = 0; j < Node::MAXCHARNUM; ++j) {
					if (search(p->next[j], word.substr(i - word.begin() + 1)))
						return true;
				}
				return false;
			}
		}
		return (p) ? bool(p->count) : false;
	}
public:
	WordDictionary() {
		root = new Node;
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		Node *p = root;
		for (auto c : word) {
			if (p->next[c - 'a'] == NULL) {
				p->next[c - 'a'] = new Node();
			}
			p = p->next[c - 'a'];
		}
		++(p->count);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return search(root, word);
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main()
{
	/*
	Trie trie;
	trie.insert("good");
	trie.insert("go");
	trie.insert("goto");
	trie.insert("mom");
	trie.insert("have");
	trie.insert("had");
	trie.insert("dult");
	cout << "key:s\t" << trie.search("key") << endl;
	cout << "good:s\t" << trie.search("good") << endl;
	cout << "goto:s\t" << trie.search("goto") << endl;
	cout << "go:s\t" << trie.search("go") << endl;
	cout << "m:f\t" << trie.startsWith("m") << endl;
	cout << "d:f\t" << trie.startsWith("d") << endl;
	cout << "a:f\t" << trie.startsWith("a") << endl;
	*/
	WordDictionary wordDictionary;
	wordDictionary.addWord("a");
	wordDictionary.addWord("ab");
	//cout << wordDictionary.search("a.")<<endl;
	//cout << wordDictionary.search(".") << endl;
	//cout << wordDictionary.search("a") << endl;
	//cout << wordDictionary.search("aa") << endl;
	//cout << wordDictionary.search("a") << endl;
	//cout << wordDictionary.search("a.") << endl;
	cout << wordDictionary.search(".b") << endl;
	cout << wordDictionary.search("..") << endl;
	return 0;
}