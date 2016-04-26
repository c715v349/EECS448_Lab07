#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

#include "LinkedList.h"

class Test
{
	public:
	Test();
	void runTests();
	bool test_af();
	bool test_ab();
	bool test_se();
	bool test_ie();
	bool test_rf();
	bool test_rb();
	bool test_si();
	bool test_tv();
	void print();
	private:
        LinkedList<int> list;
        int score;

};

#endif
