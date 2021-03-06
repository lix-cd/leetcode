// 152. Maximum Product Subarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int maxVal = INT_MIN;
		int minVal = INT_MAX;
		int curMin = INT_MAX;
		int curMax = INT_MIN;
		int lastMin = 1;
		int lastMax = 1;
		auto iter = nums.begin();
		while (iter != nums.end())
		{
			curMax = max(*iter, max((*iter)*lastMax,(*iter)*lastMin));
			curMin = min(*iter, min((*iter)*lastMax, (*iter)*lastMin));
			if (curMax > maxVal)
			{
				maxVal = curMax;
			}
			if (curMin < minVal)
			{
				minVal = curMin;
			}
			lastMax = curMax;
			lastMin = curMin;
			iter++;
		}
		return maxVal;
	}
};

int main()
{
	vector<int> input = { -2,0,-1 };
	Solution sol;
	cout << sol.maxProduct(input) << endl;
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
