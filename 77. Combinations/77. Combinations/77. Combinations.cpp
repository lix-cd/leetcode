// 77. Combinations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	vector<vector<int>> res;
	void dfs(int nLeft, int kLeft,vector<int> vec)
	{
		if (kLeft == 0) //找到一个解
		{
			res.push_back(vec);
			return;
		}

		if (nLeft == 0)
		{
			return;
		}

		if (nLeft != 0)
		{
			dfs(nLeft - 1, kLeft, vec); //跳过此元素
			dfs(nLeft - 1, kLeft -1, (vec.push_back(nLeft),vec)); //添加此元素
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<int> vec;
		dfs(n, k, vec);
		return res;
	}
};
int main()
{
	int n, k;
	cin >> n >> k;
	Solution sol;
	vector<vector<int>> result = sol.combine(n, k);
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
