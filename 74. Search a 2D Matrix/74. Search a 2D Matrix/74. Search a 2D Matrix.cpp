// 74. Search a 2D Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


//二分查找
class Solution {
public:
	int rows;
	int cols;

	void index2pos(int index, int& row, int& col)
	{
		col = index % cols;
		row = index / cols;
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int maxIndex;
		this->rows = rows;
		this->cols = cols;
		maxIndex = rows * cols - 1;

		int low = 0;
		int high = maxIndex;
		int row;
		int col;
		int mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			index2pos(mid, row, col);
			if (matrix[row][col] < target)
			{
				low = mid + 1;
			}
			else if (matrix[row][col] > target)
			{
				high = mid - 1;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{

	vector<vector<int>> input;
	input = {
	{1,3,5,7},
	{10,11,16,20},
	{23,30,34,50}
	};

	Solution sol;

	if (sol.searchMatrix(input, 6))
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}

	//Solution sol;
	//int row;
	//int col;
	//sol.rows = 3;
	//sol.cols = 4;
	//sol.index2pos(7, row, col);
	//cout << row << " " << col;
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
