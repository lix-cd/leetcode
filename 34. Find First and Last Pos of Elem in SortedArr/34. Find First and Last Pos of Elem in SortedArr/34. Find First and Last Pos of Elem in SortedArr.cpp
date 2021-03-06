// 34. Find First and Last Pos of Elem in SortedArr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	vector<int> searchRange(vector<int>& nums, int target) {
		//二分查找
		if (nums.empty())
		{
			return { -1,-1 };
		}
		if (nums.size() == 1)
		{
			if (*(nums.begin()) == target)
			{
				return { 0,0 };
			}
			else
			{
				return { -1,-1 };
			}
		}
		int low = 0, high = nums.size() -1;
		cout << "size of vector " << nums.size() << endl;
		int mid;
		int pos = -1;
		int start, end;
		//int mid;
		while (low <= high)
		{
			mid = (high + low) / 2;

			if (nums[mid] > target) //在左侧
			{
				high = mid - 1;
			}
			else if (nums[mid] < target)
			{
				low = mid + 1;
			}
			else if (nums[mid] == target)
			{
				pos = mid; //找到
				break;
			}
		}
		if (pos == -1)
		{
			return { -1,-1 };
		}

		cout << "pos "<< pos << endl;

		start = end = pos;

		while (start != 0)
		{
			if (nums[start-1] == nums[pos])
			{
				start--;
			}
			else
				break;
		}

		while (end != nums.size()-1)
		{
			if (nums[end+1] == nums[pos])
			{
				end++;
			}
			else
				break;
		}
		return { start,end };

	}
};

int main()
{
	vector<int> vec = { 0,0,2,3,4,4,4,5};
	Solution sol;
	vector<int> result = sol.searchRange(vec,5);
	
	vector<int>::iterator iter = result.begin();

	while (iter != result.end())
	{
		cout << *iter << endl;
		iter++;
	}

    //std::cout << "Hello World!\n"; 
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
