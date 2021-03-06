// 31. Next Permutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//康托展开
	void nextPermutation(vector<int>& nums) {
		auto first = -1;
		//先找第一个比右面小的数
		vector<int>::iterator iterSmall;
		vector<int>::iterator iterLarge;
		for (iterSmall = nums.end() - 2; iterSmall >= nums.begin(); iterSmall--)
		{
			if (*iterSmall < *(iterSmall + 1))
			{
				first = *iterSmall;
				break;
			}
			if (iterSmall == nums.begin())
				break;
		}
		if (first == -1) 
		{
			reverse(nums.begin(), nums.end());
			return;
		}
		auto firstLarger = -1;
		//再找比这个数大的数
		for (auto iterLarge = nums.end() - 1; iterLarge >= nums.begin(); iterLarge--)
		{
			if (*iterLarge > first)
			{
				swap(*iterSmall, *iterLarge);
				break;
			}
			if (iterLarge == nums.begin())
				break;
		}
		//然后排序
		sort(iterSmall + 1, nums.end());
	}
};

int main()
{
	vector<int> input = { 1,2,3 };
	Solution sol;
	sol.nextPermutation(input);
	auto iter = input.begin();
	while (iter != input.end())
	{
		cout << *iter << endl;
		iter++;
	}
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
