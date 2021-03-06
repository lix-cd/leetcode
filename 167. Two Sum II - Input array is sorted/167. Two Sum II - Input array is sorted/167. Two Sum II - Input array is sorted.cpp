// 167. Two Sum II - Input array is sorted.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		auto iter1 = numbers.begin();
		auto iter2 = numbers.end() - 1;
		while (iter1 != iter2)
		{
			if (*iter1 + *iter2 > target)
			{
				iter2--;
			}
			else if (*iter1 + *iter2 > target)
			{
				iter1++;
			}
			else
			{
				return { iter1 - numbers.begin(),iter2 - numbers.begin() };
			}
		}
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
