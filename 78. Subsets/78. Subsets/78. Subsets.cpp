// 78. Subsets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int subsetsNum = pow(2, nums.size());
		vector<vector<int>> result;
		int curSubset = 0;
		while (curSubset < subsetsNum)
		{
			int curBit = curSubset;
			vector<int> vec;
			int index = 0;
			while (curBit)
			{
				if (curBit % 2 == 1)
				{
					vec.push_back(nums[index]);
				}
				curBit >>= 1;
				index++;
			}
			result.push_back(vec);
			curSubset++;
		}

		return result;

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
