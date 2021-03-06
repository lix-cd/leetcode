// 15. 3Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end());
		set<vector<int>> result;
		auto iter = nums.begin();
		vector<int>::iterator lowIter = nums.begin();
		vector<int>::iterator highIter = nums.end() - 1;
		while (iter != nums.end())
		{
			int sum = -*iter;
			lowIter = nums.begin();
			highIter = nums.end() - 1;
			while (highIter > lowIter)
			{
				if (highIter == iter)
				{
					highIter--;
					continue;
				}
				if (lowIter == iter)
				{
					lowIter++;
					continue;
				}
				if (*highIter + *lowIter > sum)
					highIter--;
				else if (*highIter + *lowIter < sum)
					lowIter++;
				else
				{
					vector<int> vec = { *lowIter,*iter,*highIter };
					sort(vec.begin(), vec.end());
					result.insert(vec);
					highIter--;
					lowIter++;
					//break;
				}
			}
			iter++;
		}
		ret.assign(result.begin(), result.end());
		return ret;
	}
};

int main()
{
	Solution sol;
	vector<int> input = { -1,0,1,2,-1,-4 };
	vector<vector<int>> result;
	result = sol.threeSum(input);
	auto iter = result.begin();
	while (iter != result.end())
	{
		auto innerIter = iter->begin();
		while (innerIter != iter->end())
		{
			cout << *innerIter << " ";
			innerIter++;
		}
		cout << endl;
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
