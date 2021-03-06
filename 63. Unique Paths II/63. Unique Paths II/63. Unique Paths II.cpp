// 63. Unique Paths II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector<vector<int>> waysGrid = obstacleGrid;
		int rows = waysGrid.size();
		int cols = waysGrid[0].size();

		if (obstacleGrid[0][0] == 1)
		{
			return 0;
		}
		if (obstacleGrid[rows - 1][cols - 1] == 1)
		{
			return 0;
		}
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				if (row == 0 && col == 0)
					waysGrid[row][col] = 1;
				else if (col == 0)
				{
					if (obstacleGrid[row - 1][col] == 1)
						waysGrid[row][col] = 0;
					else
						waysGrid[row][col] = waysGrid[row - 1][col];
				}
				else if (row == 0)
				{
					if (obstacleGrid[row][col - 1] == 1)
						waysGrid[row][col] = 0;
					else
						waysGrid[row][col] = waysGrid[row][col - 1];
				}
				else
				{
					if (!obstacleGrid[row - 1][col]&& !obstacleGrid[row][col-1]) //没有障碍
					{
						waysGrid[row][col] = waysGrid[row][col - 1]+waysGrid[row-1][col];
					}
					else if (obstacleGrid[row - 1][col]&& !obstacleGrid[row][col - 1])
					{
						waysGrid[row][col] = waysGrid[row][col - 1];
					}
					else if (!obstacleGrid[row - 1][col]&&obstacleGrid[row][col - 1])
					{
						waysGrid[row][col] = waysGrid[row-1][col];
					}
					else if (obstacleGrid[row - 1][col] && obstacleGrid[row][col - 1]) //上面和左面都有障碍
					{
						waysGrid[row][col] = 0;
					}

				}
			}
		}
		return waysGrid[rows - 1][cols - 1];
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> obstacleGrid;
	obstacleGrid = { {0,1},{1,0} };
	cout<<sol.uniquePathsWithObstacles(obstacleGrid);
	return 0;
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
