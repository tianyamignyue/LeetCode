#pragma once
#include <iostream>

using namespace std;
class Solution {
public:
	int trailingZeroes(int n) {
		int res = 0;
		while (n > 0) {
			res += n / 5;
			n /= 5;
		}
		return res;
	}
};
int main()
{

	//long long n = 1;
	//unsigned zero = 0;
	//for(unsigned i = 1; i <= 30; ++i){
	//	n *= i;
	//	if(n % 10 == 0){
	//		++zero;
	//		n /= 10;
	//	}
	//	cout<<i<<"\t--\t"<<n;
	//	for(int j = 0; j < zero; ++j)
	//		cout<<'0';
	//	cout<<endl;
	//	cout<<i<<"\t--\t"<<n<<endl;
	//}
	Solution s;
	cout << s.trailingZeroes(625);
	return 0;
}