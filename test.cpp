#include "test.h"

Test::Test() : score(0)
{

}

void Test::runTests()
{
	std::cout << "\n\nadd front: ";
		if (test_af()) {std::cout << "Pass"; score++;}
		else std::cout << "Fail";
	std::cout << "\n\nadd back: ";
		if (test_ab()) {std::cout << "Pass"; score++;}
		else std::cout << "Fail";
	std::cout << "\n\nsearch: ";
		if (test_se()) {std::cout << "Pass"; score++;}
		else std::cout << "Fail";
	std::cout << "\n\nis empty: ";
		if (test_ie()) {std::cout << "Pass"; score++;}
		else std::cout << "Fail";
	std::cout << "\n\nremove front: ";
		if (test_rf()) {std::cout << "Pass"; score++;}
		else std::cout << "Fail";
	std::cout << "\n\nremove back: ";
		if (test_rb()) {std::cout << "Pass"; score++;}
		else std::cout << "Fail";
	std::cout << "\n\nsize: ";
		if (test_si()) {std::cout << "Pass"; score++;}
		else std::cout << "Fail";
	std::cout << "\n\nto vector: ";
		if (test_tv()) {std::cout << "Pass"; score++;}
		else std::cout << "Fail";
	std::cout << "\n\nTotal: " << score << "/8 tests passed.\n";
}
void Test::print()
{
	std::vector<int> vec;
	vec = list.toVector();
	std::cout << "Current list: (";
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (i == vec.size()-1)
			std::cout << vec.at(i);
		else
    		std::cout << vec.at(i) << ",";
	}
	std::cout << ")\n";
}

bool Test::test_af()
{
	
	std::vector<int> vec;
	bool isPass = true;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Adding to front: " << i << "\n";
		list.addFront(i);
		vec = list.toVector();
		if ( vec.at(vec.size()-1-i) != i )
			isPass = false;
		print();
	}
	
	return isPass;

}
bool Test::test_ab()
{
	std::vector<int> vec;
	bool isPass = true;
	int j = 0;
	for (int i = 3; i < 6; i++)
	{
		std::cout << "Adding to back: " << i << "\n";
		list.addBack(i);
		vec = list.toVector();
		if ( vec.at(vec.size()-1-j) != i )
			isPass = false;
		j++;
		print();
	}
	return isPass;
}
bool Test::test_se()
{
	std::vector<int> vec;
	vec = list.toVector();
	bool isPass = true;
	
	std::cout << "\nsearching for 46 in ";
	print();
	if ( std::find(vec.begin(), vec.end(), 46) != vec.end() )
		isPass = false;

	std::cout << "searching for 2 in ";
	print();
	if (!(std::find(vec.begin(), vec.end(), 2) != vec.end()) )
		isPass = false;

	return isPass;
}
bool Test::test_ie()
{
	bool isPass = true;
	LinkedList<int> tempList;
	std::cout << "\nTesting an empty list\n";
	if (!tempList.isEmpty())
		isPass = false;
	std::cout << "Testing a full list\n";
	if (list.isEmpty())
		isPass = false;

	return isPass;
}
bool Test::test_rf()
{
	bool isPass = true;
	std::vector<int> vec;
	std::vector<int> vec2;
	std::cout << "\n";
	print();
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Removing Front\n";
		vec = list.toVector();
		list.removeFront();
		vec2 = list.toVector();
		std::cout << "Checking size...";
		if (vec2.size() != vec.size()-1)
			isPass = false;
		std::cout << "Checking array\n";
		for (unsigned int j = 0; j < vec2.size(); j++)
		{
			if (vec2.at(j) != vec.at(j+1))
				isPass = false;
		}
		print();
	}
	return isPass;
}
bool Test::test_rb()
{
	bool isPass = true;
	std::vector<int> vec;
	std::vector<int> vec2;
	std::cout << "\n";
	print();
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Removing Back\n";
		vec = list.toVector();
		list.removeBack();
		vec2 = list.toVector();
		std::cout << "Checking size...";
		if (vec2.size() != vec.size()-1)
			isPass = false;
		std::cout << "Checking array\n";
		for (unsigned int j = 0; j < vec2.size(); j++)
		{
			if (vec2.at(j) != vec.at(j))
				isPass = false;
		}
		print();
	}
	return isPass;
}
bool Test::test_si()
{
	bool isPass = true;
	LinkedList<int> tempList;
	std::cout << "\nTesting an empty list\n";
	if (tempList.size() != 0)
		isPass = false;
	std::cout << "Testing a full list\n";
	tempList.addFront(1);
	tempList.addFront(1);
	if (tempList.size() != 2)
		isPass = false;
	return isPass;

}
bool Test::test_tv()
{
	bool isPass = true;
	LinkedList<int> tempList;
	std::vector<int> vec;
	std::cout << "\nChecking vector additions into an empty list\n";
	for (int j = 0; j < 3; j++)
	{
		tempList.addFront(j);
		vec = tempList.toVector();
		if (vec.front() != j)
			isPass = false;
	}
	
	return isPass;
}
