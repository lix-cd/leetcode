// 64. Minimum Path Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int curLoop = 1;
		int maxRow = grid.size();
		int maxCol = grid[0].size();
		vector<vector<int>> minPathGrid = grid;
		minPathGrid[0][0] = grid[0][0];
		while (curLoop < maxRow || curLoop < maxCol)
		{
			//第0行当前圈的元素 为 网格上的值加上 左侧的最优值 若存在
			if (curLoop < maxCol)
				minPathGrid[0][curLoop] = grid[0][curLoop] + minPathGrid[0][curLoop - 1];
			int curRow = 1;
			while (curRow <= curLoop)
			{
				if (curRow == maxRow)
				{
					break;
				}
				if (curLoop < maxCol)
				minPathGrid[curRow][curLoop]
					= (minPathGrid[curRow - 1][curLoop]
					< minPathGrid[curRow][curLoop - 1]
					? minPathGrid[curRow - 1][curLoop]
					: minPathGrid[curRow][curLoop - 1])
					+grid[curRow][curLoop];
				curRow++;
				//if (curRow == maxRow - 1)
				//{
				//	break;
				//}
			}

			//当前圈第0列的元素 为 网格上的值 加上 上面的值  若存在
			if(curLoop<maxRow)
				minPathGrid[curLoop][0] = grid[curLoop][0]+minPathGrid[curLoop - 1][0];

			int curCol = 1;
			while (curCol <= curLoop)
			{
				if (curCol == maxCol)
				{
					break;
				}
				if (curLoop < maxRow)
				minPathGrid[curLoop][curCol]
					= (minPathGrid[curLoop - 1][curCol]
						< minPathGrid[curLoop][curCol - 1]
						? minPathGrid[curLoop - 1][curCol]
						: minPathGrid[curLoop][curCol - 1])
					+ grid[curLoop][curCol];
				curCol++;
				//if (curCol == maxCol-1)
				//{
				//	break;
				//}
			}

			if (curLoop < maxRow&&curLoop < maxCol)
			minPathGrid[curLoop][curLoop]
				= (minPathGrid[curLoop - 1][curLoop]
					< minPathGrid[curLoop][curLoop - 1]
					? minPathGrid[curLoop - 1][curLoop]
					: minPathGrid[curLoop][curLoop - 1])
				+ grid[curLoop][curLoop];

			curLoop++;
		}
		return minPathGrid[maxRow - 1][ maxCol - 1 ];
	}
};

int main()
{
	vector<vector<int>> grid = { {1,2,5},{3,2,1} };
	Solution sol;
	cout << sol.minPathSum(grid);
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
