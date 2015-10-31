#pragma once
#include <iostream>

using namespace std;
// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
	if (version >= 2)
		return true;
	else
		return false;
}
class Solution {
	int find(int begin, int end) {
		while (begin <= end) {
			int mid = ((long long)begin + end) / 2;
			if (isBadVersion(mid)) {
				if (mid == begin)
					return mid;
				else
					end = mid - 1;
			}
			else {
				if (mid == end) {
					return mid + 1;
				}
				else {
					begin = mid + 1;
				}
			}
		}
	}
public:
	int firstBadVersion(int n) {
		if (n < 1)
			return 0;
		return find(1, n);
	}
};
int main()
{
	cout << (new Solution)->firstBadVersion(3);
	return 0;
}