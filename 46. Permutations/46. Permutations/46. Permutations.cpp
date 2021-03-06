// 46. Permutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//使用stl中next_permutation函数的解法
//class Solution {
//public:
//	vector<vector<int>> permute(vector<int>& nums) {
//		vector<vector<int>> result;
//		sort(nums.begin(), nums.end());
//		result.push_back(nums);
//		while (next_permutation(nums.begin(), nums.end()))
//		{
//			result.push_back(nums);
//		}
//		return result;
//	}
//};

class Solution {
public:

	vector<int> input;
	vector<vector<int>> result;

	void dfs(vector<int> cur)
	{
		auto iter = input.begin();
		while (iter != input.end())
		{
			if (find(cur.begin(), cur.end(), *iter) == cur.end()) //找不到
			{
				cur.push_back(*iter);
				dfs(cur);
			}
			iter++;
		}
		result.push_back(cur);
	}

	vector<vector<int>> permute(vector<int>& nums) {
		this->input = nums;
		dfs(vector<int>());
		return this->result;
	}
};

int main()
{
	int n;
	int cur;
	vector<int> input;
	vector<vector<int>> result;
	cin >> n;
	while (n--)
	{
		cin >> cur;
		input.push_back(cur);
	}
	Solution sol;
	result = sol.permute(input);
	auto iter = result.begin();
	while (iter != result.end())
	{
		auto innerIter = iter->begin();
		while (innerIter != iter->end())
		{
			cout << *innerIter<<" ";
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
