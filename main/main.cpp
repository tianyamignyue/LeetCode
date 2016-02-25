#include <iostream>
using namespace std;

#include "solution162.h"

int main()
{
	//test();
	int p = 3;
	for (int i = 0; i < 19; ++i) {
		cout << setw(10) << p <<endl;
		p *= 3;
	}
}