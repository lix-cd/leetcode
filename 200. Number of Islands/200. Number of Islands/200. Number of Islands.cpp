// 200. Number of Islands.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<bool>> visited;
	vector<vector<char>> grid;
	int result;
	int rows;
	int cols;


	void dfs(int row,int col)
	{
		if (grid[row][col] == '0'||visited[row][col])
		{
			return;
		}
		visited[row][col] = true;
		if (row < rows - 1)
		{
			dfs(row + 1, col); //右
		}
		if (col < cols - 1)
		{
			dfs(row, col + 1);//下
		}
		if (row > 0)
		{
			dfs(row - 1, col); //左
		}
		if (col > 0)
		{
			dfs(row, col - 1);//上
		}
		return;
	}

	int numIslands(vector<vector<char>>& grid) {
		this->grid = grid;
		if (grid.empty())
		{
			return 0;
		}
		result = 0;
		this->rows = grid.size();
		this->cols = grid[0].size();
		visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				if (!visited[row][col]&&grid[row][col]=='1')
				{
					result++;
					dfs(row, col);
				}
			}
		}
		return result;
	}
};

int main()
{
	vector<vector<char>> grid =
	{
	{'1','1','1','1','0'},
	{'1','1','0','1','0'},
	{'1','1','0','0','0'},
	{'0','0','0','0','0'} };
	Solution sol;
	cout << sol.numIslands(grid) << endl;
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
