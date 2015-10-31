#pragma once
#include <iostream>
#include <string>

using namespace std;

char hash[256] = { 0 };
char de_hash(char c) {
	for (int i = 0; i < 256; ++i) {
		if (::hash[i] == c)
			return i;
	}
	return 0;
}


bool isIsomorphic(string s, string t) {
	for (int i = 0; i < s.length(); ++i) {
		if (de_hash(t[i]) == 0 && ::hash[s[i]] == 0)
			::hash[s[i]] = t[i];
	}
	for (int i = 0; i < s.length(); ++i) {
		char c = de_hash(s[i]);
		if (c != 0)
			s[i] = c;
	}
	if (s == t)
		return true;
	else
		return false;
}

int main()
{
	cout << isIsomorphic("baa", "cfa");
	return 0;
}