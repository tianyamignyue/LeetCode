#pragma once

//93. Restore IP Addresses			https://leetcode.com/problems/restore-ip-addresses/

#include "leetCodeHead.h"

class Solution {
	void backTracking(string &s, int index, string ip, int nip, int ipNum, vector<string> &result) {
		//is return 
		if (ipNum > 4)
			return;
		if (index >= s.length()) {
			if (ipNum == 4) {
				ip += "." + to_string(nip);
				result.push_back(ip);
				return;
			} else {
				return;
			}
		}

		//process
		if (nip == -1) {
			nip = s[index] - '0';
			backTracking(s, index+1, ip, nip, ipNum, result);
		} else {
			//next
			if (nip != 0 && (nip = nip * 10 + s[index] - '0') < 256) {
				backTracking(s, index+1, ip, nip, ipNum, result);
			}
			//retore 
			nip /= 10;
			ip = ip.empty() ? to_string(nip) : ip + "." + to_string(nip);
			++ipNum, nip = -1;
			backTracking(s, index, ip, nip, ipNum, result);
		}
	}
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		string ip;
		backTracking(s, 0, ip, -1, 1, result);
		return result;
	}
};

void test() {
	Solution s;
	vector<string> result;
	result = s.restoreIpAddresses("010010");

	for (auto s : result) {
		cout << s << endl;
	}

}