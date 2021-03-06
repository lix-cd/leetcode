// 75. Sort Colors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

//桶排序

class Solution {
public:
	void sortColors(vector<int>& nums) {
		vector<int> result;
		int r = 0, w = 0, b = 0;
		auto iter = nums.begin();
		while (iter != nums.end())
		{
			switch (*iter)
			{
			case 0:
				r++;
				break;
			case 1:
				w++;
				break;
			case 2:
				b++;
				break;
			default:
				break;
			}
			iter++;
		}
		while (r--)
		{
			result.push_back(0);
		}
		while (w--)
		{
			result.push_back(1);
		}
		while (b--)
		{
			result.push_back(2);
		}
		nums = result;
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
