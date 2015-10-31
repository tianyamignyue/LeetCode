#pragma once
#include <iostream>

using namespace std;

class Solution {
	string getstr(string str, int &i) {
		string res = "";
		while (i < str.length() && str[i] == '0')
			i++;
		while (i < str.length() && str[i] != '.') {
			res += str[i++];
		}
		if (i < str.length() && str[i] == '.')
			i++;
		return res;
	}
public:
	int compare(string str1, string str2) {
		int len1 = str1.length(), len2 = str2.length();
		if (len1 > len2)
			return 1;
		else if (len1 < len2)
			return -1;
		else {
			int minus = str1.compare(str2);
			if (minus > 0)
				return 1;
			else if (minus < 0)
				return -1;
			else
				return 0;
		}
	}
public:
	int compareVersion(string version1, string version2) {
		int i = 0, j = 0, res;
		string sub1, sub2;
		while (i < version1.length() && j < version2.length()) {
			sub1 = getstr(version1, i);
			sub2 = getstr(version2, j);
			int minus = compare(sub1, sub2);
			if (minus != 0)
				return minus;
		}
		while (i < version1.length()) {
			sub1 = getstr(version1, i);
			if (!sub1.empty())
				return 1;
		}
		while (j < version2.length()) {
			sub2 = getstr(version2, j);
			if (!sub2.empty())
				return -1;
		}
		return 0;
	}
};

int main()
{
	Solution s;
	cout << s.compareVersion("1.0", "1") << endl;
	cout << s.compareVersion("1.0.1", "1") << endl;
	cout << s.compareVersion("1.0.0", "1") << endl;
	return 0;
}