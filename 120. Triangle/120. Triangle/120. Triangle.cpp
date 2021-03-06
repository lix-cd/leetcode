// 120. Triangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//using only O(n) extra space solution
class Solution {
public:
	vector<vector<int>> dp;
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> dp = triangle;
		int rows = triangle.size();
		for (int i = 0; i < rows; i++)
		{
			int cols = i;
			for (int col = 0; col < cols+1; col++)
			{
				if (i == 0 && col == 0)
				{
					dp[0][0] = triangle[0][0];
				}
				else if (col == 0)
				{
					dp[i][col] = dp[i-1][col] + triangle[i][col];
				}
				else if (col == cols)
				{
					dp[i][col] = triangle[i][col] + dp[i-1][col-1];
				}
				else
				{
					dp[i][col] = min(triangle[i][col] + dp[i-1][col],
						triangle[i][col] + dp[i - 1][col - 1]);
				}

			}
		}
		auto iter = dp[rows - 1].begin();
		int min = INT_MAX;
		while (iter != dp[rows - 1].end())
		{
			if (*iter < min)
			{
				min = *iter;
			}
			iter++;
		}
		this->dp = dp;
		return min;
	}
};

int main()
{
	vector<vector<int>> tri;
	tri = { {2},{3,4},{6,5,7},{4,1,8,3} };
	Solution sol;
	cout<<sol.minimumTotal(tri)<<endl;
	auto iter = sol.dp.begin();
	while (iter != sol.dp.end())
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
