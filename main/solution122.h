#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res = 0;
		bool hasStock = false;
		for (int i = 0; i < prices.size(); i++) {
			int priceNow = prices[i];
			int priceNext;
			if (i == prices.size() - 1)
				priceNext = 0;
			else
				priceNext = prices[i + 1];
			if (priceNext > priceNow && (!hasStock)) {
				hasStock = true;
				res -= priceNow;
			}
			if (priceNext < priceNow && (hasStock)) {
				hasStock = false;
				res += priceNow;
			}
		}
		return res;
	}
};

int main()
{
	vector<int> p;
	p.push_back(3);
	p.push_back(5);

	p.push_back(7);
	p.push_back(2);
	p.push_back(3);
	p.push_back(6);
	p.push_back(6);
	p.push_back(9);
	p.push_back(2);
	p.push_back(5);
	p.push_back(7);
	p.push_back(1);
	p.push_back(1);

	cout << (new Solution())->maxProfit(p);
}