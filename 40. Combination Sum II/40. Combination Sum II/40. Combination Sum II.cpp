// 39. Combination Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> candidates;

	vector<vector<int>> result;

	int size;
	int target;

	void dfs(int index, int currentSum, vector<int> CurRes)
	{
		if (currentSum == target) //找到解
		{
			result.push_back(CurRes);
			return;
		}

		if (currentSum > target)
		{
			return;
		}

		if (index == size) //已经到达数组末尾
		{
			return;
		}

		while (index < size)
		{
			CurRes.push_back(candidates[index]);
			dfs(index+1, currentSum+candidates[index], CurRes);
			CurRes.pop_back();
			index++;
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		this->target = target;
		size = candidates.size();
		dfs(0, 0, vector<int>());
		sort(result.begin(), result.end());
		auto newEnd = unique(result.begin(), result.end());
		result.erase(newEnd, result.end());
		return result;
	}
};

int main()
{
	vector<vector<int>> result;
	Solution sol;
	vector<int> vec = { 10,1,2,7,6,1,5 };
	result = sol.combinationSum(vec, 8);
	vector<vector<int>>::iterator iter = result.begin();
	vector<int>::iterator innerIter;

	while (iter != result.end())
	{
		innerIter = iter->begin();
		while (innerIter != iter->end())
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
