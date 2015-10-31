#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	int *prime;
	int num;
	bool isPrime(int n) {
		for (int i = 0; i < num && prime[i] * prime[i] <= n; ++i) {
			if (n % prime[i] == 0)
				return false;
		}
		prime[num++] = n;
		cout << "prime:" << n << endl;
		return true;
	}
public:
	int countPrimes(int n) {
		int count = 0;
		prime = new int[n];
		num = 0;
		if (n <= 1)
			return 0;
		for (int i = 2; i < n; ++i) {
			if (isPrime(i))
				++count;
		}
		return count;
	}
};

int main()
{
	for (int i = 0; i < 46; i++)
		cout << char('A' + i) << endl;
	vector<int> v;

	for (auto)
		return 0;
}