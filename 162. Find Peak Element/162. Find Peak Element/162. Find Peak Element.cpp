// 162. Find Peak Element.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int start = 0;
		int end = nums.size() - 1;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (start == end)
				return nums[mid];
			else if (nums[mid] < nums[mid + 1])
			{
				start = mid + 1;
			}
			else
			{
				end = mid -1;
			}
		}
	}
};

int main()
{
	vector<int> input = { 1,2,3,1 };
	Solution sol;
	cout << sol.findPeakElement(input) << endl;
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
