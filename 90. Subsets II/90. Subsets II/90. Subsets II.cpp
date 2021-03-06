// 90. Subsets II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ret;
		set<vector<int>> result;
		int subsetNums = (int)pow(2, nums.size());
		int curSubset = 0;
		while (curSubset < subsetNums)
		{
			int curBit = curSubset;
			int index = 0;
			vector<int> vec;
			while (curBit)
			{
				if (curBit % 2 == 1)
				{
					vec.push_back(nums[index]);
				}
				curBit >>= 1;
				index++;
			}
			//ret.push_back(vec);
			sort(vec.begin(), vec.end());
			result.insert(vec);
			curSubset++;
		}
		copy(result.begin(), result.end(), back_inserter(ret));
		return ret;
	}
};

int main()
{
	vector<int> input;
	vector<vector<int>> result;
	int n;
	int i;
	cin >> n;
	while (n--)
	{
		cin >> i;
		input.push_back(i);
	}
	Solution sol;
	result = sol.subsetsWithDup(input);
	vector<vector<int>>::iterator iter = result.begin();
	vector<int>::iterator innerIter;
	while (iter != result.end())
	{
		innerIter = (*iter).begin();
		while (innerIter != (*iter).end())
		{
			cout << *innerIter << " ";
			innerIter++;
		}
		iter++;
		cout << endl;
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
