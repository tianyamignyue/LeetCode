#pragma once
#include <iostream>
#include <string>
using namespace std;

class Solution {
	string getNext(string str) {
		string res = "";
		char c = str[0];
		char strInt[10];
		unsigned int num = 1;
		for (int i = 1; i < str.length(); i++) {
			if (str[i] == c) {
				num++;
			}
			else {
				sprintf(strInt, "%u", num);
				res.append(strInt);
				strInt[0] = c;
				strInt[1] = '\0';
				res.append(strInt);
				c = str[i];
				num = 1;
			}
		}
		sprintf(strInt, "%u", num);
		res.append(strInt);
		strInt[0] = c;
		strInt[1] = '\0';
		res.append(strInt);
		return res;
	}
public:
	string countAndSay(int n) {
		string res = "";
		string temp;
		if (n <= 0)
			return res;
		res.append("1");
		for (int i = 1; i < n; i++) {
			temp = getNext(res);
			res.resize(0);
			res.append(temp);
		}
		return res;
	}
};

int main()
{
	Solution s;
	//for(int i = 0; i < 10; i++)
	cout << s.countAndSay(2) << endl;
	return 0;
}