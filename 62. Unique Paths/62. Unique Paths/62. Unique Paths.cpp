// 62. Unique Paths.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> result;
		//result.reserve(m);

		for (int row = 0; row < m; row++)
		{
			result.push_back(vector<int>());  //行循环
			for (int col = 0; col < n; col++)
			{
				result[row].push_back(int());
				result[row][col] = -1;
			}
		}

		//vector<int> curRow;
		for (int row = 0; row < m; row++)
		{
			for (int col = 0; col < n; col++)
			{
				//curRow.clear();
				if (row == 0 || col == 0)
				{
					result[row][col] = 1;
				}
				else
				{
					result[row][col] = result[row - 1][col] + result[row][col - 1];
				}
			}
		}
		return result[m - 1][n - 1];
	}
};

int main()
{
	Solution sol;
	cout << sol.uniquePaths(7, 3);
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
