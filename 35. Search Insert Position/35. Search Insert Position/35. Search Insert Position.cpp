// 35. Search Insert Position.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (target < nums[0])
			return 0;
		vector<int>::iterator iter = nums.begin();
		while (iter!=nums.end())
		{
			if (target == *iter)
			{
				return distance(nums.begin(), iter);
			}
			if ((iter + 1)!=nums.end()&&target > *iter && target < *(iter+1))
			{
				return distance(nums.begin(), iter) + 1;
			}
			iter++;
		}
		return nums.size();
	}
};

int main()
{
	int arr[] = { 1,3,5,6 };
	vector<int> vec(arr, arr + 3);
	Solution sol;

    std::cout << sol.searchInsert(vec,7); 
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
