#pragma once
//166. Fraction to Recurring Decimal
//https ://leetcode.com/problems/fraction-to-recurring-decimal/

#include "leetCodeHead.h"
class Solution {
	template <typename Type>
	Type calOneStep(Type & numerator, Type & denominator) {
		Type part = 0;
		if (numerator > denominator) {
			part = numerator / denominator;
			numerator = numerator % denominator;
		}
		numerator *= 10;
		return part;
	}
	template <typename Type>
	string fractionToDecimal(Type numerator, Type denominator) {
		if (!numerator)
			return "0";
		string neg;
		if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
			neg = "-";
		numerator = numerator < 0 ? 0 - numerator : numerator;
		denominator = denominator < 0 ? 0 - denominator : denominator;
		string pre, aft;
		Type part = calOneStep<Type>(numerator, denominator);
		pre += to_string(part);
		if (!numerator) {
			return neg + pre;
		}
		unordered_map<Type, int> dict;
		char newfrac;
		int i = 0;
		do {
			dict.insert(pair<Type, int>(numerator, i));
			newfrac = calOneStep<Type>(numerator, denominator) + '0';
			aft += newfrac;
			if (!numerator)
				return neg + pre + "." + aft;
			auto find = dict.find(numerator);
			if (find != dict.end()) {
				return neg + pre + "." + aft.substr(0, find->second) + "(" + aft.substr(find->second) + ")";
			}
		} while (++i);
	}
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0x80000000 || denominator == 0x80000000)
			return fractionToDecimal<long long>(long long(numerator), long long(denominator));
		else 
			return fractionToDecimal<int>(numerator, denominator);
	}
};

void test() {
	Solution s;
	cout << s.fractionToDecimal(3,2) << endl;
	cout << s.fractionToDecimal(2,3) << endl;
	cout << s.fractionToDecimal(13, 12) << endl;
	cout << s.fractionToDecimal(13, 17) << endl;
	cout << s.fractionToDecimal(23, 29) << endl;
	cout << s.fractionToDecimal(37, 222) << endl;
	cout << s.fractionToDecimal(4,15) << endl;
	cout << s.fractionToDecimal(123, 999) << endl;
	//cout << s.fractionToDecimal(123456,654321) << endl;
	//cout << s.fractionToDecimal(654321,123456) << endl;
	cout << s.fractionToDecimal(0,1) << endl;
	cout << s.fractionToDecimal(550, 10) << endl;
	cout << s.fractionToDecimal(-1, -2147483648)<< endl;
	cout << s.fractionToDecimal(-2147483648,1) << endl;
}