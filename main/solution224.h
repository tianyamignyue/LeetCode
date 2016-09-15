#pragma once
#include "leetCodeHead.h"

class Solution {
public:
	// + - ( )
	int calculate(string s) {
		stack<int> num;
		stack<char> ch;
		auto it = s.begin();
		while ( it != s.end()) {
			if (*it == ' ') {
				++it;
				continue;
			}
			if (*it >= '0' && *it <= '9') {
				long long n = *it++ - '0';
				while (it != s.end() && *it >= '0' && *it <= '9') {
					n = n * 10 + (*it++ - '0');
				}
				num.push(n);
			} else {
				if (*it == '(') {
					ch.push(*it++);
				} else if (*it == '+' || *it == '-') {
					if (ch.empty() || ch.top() == '(') {
						ch.push(*it++);
					} else {
						char f = ch.top();
						ch.pop();
						int r = num.top();
						num.pop();
						int l = num.top();
						num.pop();
						if (f == '-') {
							num.push(l - r);
						} else {
							num.push(l + r);
						}

						ch.push(*it++);
					}
				} else { // ')'
					while (!ch.empty() && ch.top() != '(') {
						char f = ch.top();
						ch.pop();
						int r = num.top();
						num.pop();
						int l = num.top();
						num.pop();
						if (f == '-') {
							num.push(l - r);
						} else {
							num.push(l + r);
						}
					}
					if (!ch.empty()) {
						//"("
						ch.pop();
					}
					++it;
				}
			}// end ch

		}//end for


		while (!ch.empty()) {
			char f = ch.top();
			ch.pop();
			int r = num.top();
			num.pop();
			int l = num.top();
			num.pop();
			if (f == '-') {
				num.push(l - r);
			} else {
				num.push(l + r);
			}
		}


		return num.top();
	}

	// + - * / 
	int calculate2(string s) {
		stack<int> num;
		stack<char> ch;
		auto it = s.begin();
		while (it != s.end()) {
			if (*it == ' ') {
				++it;
				continue;
			}
			if (*it >= '0' && *it <= '9') {
				long long n = *it++ - '0';
				while (it != s.end() && *it >= '0' && *it <= '9') {
					n = n * 10 + (*it++ - '0');
				}
				num.push(n);
			} else {
				if (ch.empty()) {
					ch.push(*it++);
				} else {
					if (*it == '+' || *it == '-') {
						while (!ch.empty()) {
							char f = ch.top();
							ch.pop();
							int r = num.top();
							num.pop();
							int l = num.top();
							num.pop();
							if (f == '-') {
								num.push(l - r);
							} else if (f == '+') {
								num.push(l + r);
							} else if (f == '*') {
								num.push(l * r);
							} else if (f == '/') {
								num.push(l / r);
							}
						}

						ch.push(*it++);
					} else {// * /
						while (!ch.empty() && (ch.top() == '*' || ch.top() == '/')) {
							char f = ch.top();
							ch.pop();
							int r = num.top();
							num.pop();
							int l = num.top();
							num.pop();
							if (f == '-') {
								num.push(l - r);
							} else if (f == '+') {
								num.push(l + r);
							} else if (f == '*') {
								num.push(l * r);
							} else if (f == '/') {
								num.push(l / r);
							}
						}

						ch.push(*it++);
					}
				}
			}// end ch

		}//end for


		while (!ch.empty()) {
			char f = ch.top();
			ch.pop();
			int r = num.top();
			num.pop();
			int l = num.top();
			num.pop();
			if (f == '-') {
				num.push(l - r);
			} else if (f == '+') {
				num.push(l + r);
			} else if (f == '*') {
				num.push(l * r);
			} else if (f == '/') {
				num.push(l / r);
			}
		}


		return num.top();
	}






};

void test() {

	string str = "1*2-3/4+5*6-7*8+9/10";

	Solution s;

	cout << s.calculate2(str);

}