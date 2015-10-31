#pragma once
#include <iostream>
#include <string>

using namespace std;

#include "windows.h"


class CTimer
{
public:
	CTimer()
	{
		QueryPerformanceFrequency(&m_Frequency);
		Start();
	}
	void Start()
	{
		QueryPerformanceCounter(&m_StartCount);
	}
	double End()
	{
		LARGE_INTEGER CurrentCount;
		QueryPerformanceCounter(&CurrentCount);
		return double(CurrentCount.LowPart - m_StartCount.LowPart) / (double)m_Frequency.LowPart;
	}
	void ShowNow()
	{
		LARGE_INTEGER CurrentCount;
		QueryPerformanceCounter(&CurrentCount);
		cout << "Timer Count is:" << double(CurrentCount.LowPart - m_StartCount.LowPart) / (double)m_Frequency.LowPart << endl;
	}
private:
	LARGE_INTEGER m_Frequency;
	LARGE_INTEGER m_StartCount;
};

class Solution005 {
public:
	bool isPalindrome(string s) {
		auto start = s.begin();
		auto end = s.end();
		--end;
		while (start < end) {
			if (*start != *end) {
				return false;
			}
			++start;
			--end;
		}
		return true;
	}
public:
	string longestPalindrome(string s) {
		if (isPalindrome(s))
			return s;
		if (s.length() <= 1)
			return s;
		auto start = s.begin();
		string result;
		auto end = s.find(*start, 1);
		while (start != s.end()) {
			end = s.find(*start, start + 1 - s.begin());
			while (end != string::npos) {
				string temp = string(start, s.begin() + end + 1);
				if (temp.size() > result.size() && isPalindrome(temp)) {
					result = temp;
				}
				end = s.find(*start, end + 1);
			}
			++start;
		}
		return result;
	}
	string longestPalindrome2(string s) {
		string result;
		if (s.length() <= 1)
			return s;
		bool mat[1001][1001] = { false };
		for (int j = 0; j < s.length(); ++j) {
			for (int i = j; i < s.length(); ++i) {
				mat[i][j] = true;
			}
		}
		for (int i = s.length() - 1; i >= 0; --i) {
			for (int j = i + 1; j < s.length(); ++j) {
				if (s[i] == s[j]) {
					mat[i][j] = mat[i + 1][j - 1];
					if (mat[i][j] && j - i + 1 >result.length()) {
						result = s.substr(i, j - i + 1);
					}
				}
				else {
					mat[i][j] = false;
				}
			}
		}
		return result;
	}
};

int main005()
{
	CTimer t;
	cout << (new Solution005)->longestPalindrome2("aaaaaaaaaaaaaaaaaccaaaaaaaaa");
	cout << "ÓÃÊ±" << t.End() << "Ãë" << endl;
	return 0;
}