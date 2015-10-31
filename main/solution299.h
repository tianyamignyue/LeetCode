#pragma once

//Bulls and Cows
#include <string>
#include <iostream>
using namespace std;

class Solution299 {
public:
	string getHint(string secret, string guess) {
		int A = 0, B = 0;
		bool *use = new bool[secret.length()];
		for (int i = 0; i < guess.length(); ++i) {
			if (guess[i] == secret[i])
				++A;
			auto pos = secret.find(guess[i]);
			while (pos != string::npos) {
				if (!use[pos]) {
					use[pos] = true;
					break;
				} else {
					pos = secret.find(guess[i], pos + 1);
				}
			}
			if(pos != string::npos)
				++B;
		}
		char str[25];
		sprintf(str, "%dA%dB", A, B - A);
		string res(str);
		return res;
	}
};

void test299() {
	cout << (new Solution299)->getHint("7801", "0817");
}