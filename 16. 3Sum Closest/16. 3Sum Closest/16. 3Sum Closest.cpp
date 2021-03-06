// 16. 3Sum Closest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int diff = INT_MAX;
		int curResult;
		auto iter = nums.begin();
		while (iter != nums.end())
		{
			//int sum = -*iter;
			auto lowIter = nums.begin();
			auto highIter = nums.end() -1;
			while (highIter > lowIter)
			{
				if (iter == lowIter)
				{
					lowIter++;
					continue;
				}
				if (iter == highIter)
				{
					highIter--;
					continue;
				}
				if (abs(target - *lowIter - *highIter - *iter)<diff)
				{
					cout << "lowIter" << *lowIter << endl;
					cout << "highIter" << *highIter << endl;
					cout << "iter" << *iter << endl;
					diff = abs(target - *lowIter - *highIter - *iter);
					curResult = *lowIter + *highIter + *iter;
				}
				if (*lowIter + *highIter + *iter > target)
				{
					lowIter++;
				}
				else if (*lowIter + *highIter + *iter < target)
				{
					highIter--;
				}
				else
				{
					break;
				}
				//lowIter++;
				//highIter--;
			}
			iter++;
		}
		return curResult;
	}
};

int main()
{
	Solution sol;
	vector<int> input;
	input = { -1, 2, 1, -4 };
	cout << sol.threeSumClosest(input, 1) << endl;
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
