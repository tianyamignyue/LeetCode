#pragma once
#include <string>
#include <vector>
using namespace std;
class Solution {
	vector<string> directory;
	int index;
	int end;
	void removeD() {
		if (!directory.empty()) {
			directory.erase(directory.end() - 1);
		}
	}
	bool isPPL(const string &path) {
		if (index + 2 < end && path[index] == '.' && path[index + 1] == '.' && path[index + 2] == '/')
			return true;
		else if (index + 2 == end && path[index] == '.' && path[index + 1] == '.')
			return true;
		else
			return false;
	}
	bool isPL(const string &path) {
		if (index + 1 < end && path[index] == '.' && path[index + 1] == '/')
			return true;
		else
			return false;
	}
	void addDir(const string &path) {
		string dir = "";
		while (index < end && path[index] != '/') {
			dir += path[index++];
		}
		if (!dir.empty() && dir != "." && dir != "..")
			directory.push_back(dir);
	}
	void scapeLine(const string &path) {
		while (index < end && path[index] == '/')
			++index;
	}
	string over() {
		string result = "";
		for (auto s : directory) {
			result += ("/" + s);
		}
		if (result.length() == 0)
			result += "/";
		return result;
	}
public:
	string simplifyPath(string path) {
		if (path.length() == 0)
			return "";
		index = 0;
		end = path.length();
		if (path.length() == 0)
			return "";
		index = 0;
		end = path.length();
		while (index < end) {
			if (path[index] == '/')
				scapeLine(path);
			else if (isPL(path)) {
				index += 2;
			}
			else if (isPPL(path)) {
				index += 3;
				removeD();
			}else {
				addDir(path);
			}
		}
		return over();
	}
};
void test() {
	cout << (new Solution)->simplifyPath("///eHx/..");
}