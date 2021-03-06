// 48. Rotate Image.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		int maxRow = matrix.size();
		int maxCol = matrix[0].size();

		//转置矩阵
		int curRow = 0;
		for (curRow = 0; curRow < maxRow; curRow++) //行循环
		{
			for (int curCol = 0; curCol < curRow; curCol++) //列循环
			{
				matrix[curRow][curCol] ^= matrix[curCol][curRow];
				matrix[curCol][curRow] ^= matrix[curRow][curCol];
				matrix[curRow][curCol] ^= matrix[curCol][curRow];
			}
		}

		//翻转矩阵
		int mid = (maxRow + 1) / 2;

		for (curRow = 0; curRow < maxRow; curRow++)
		{
			for (int curCol = 0; curCol < mid-1; curCol++)
			{
				if (matrix[curRow][curCol] == matrix[curRow][maxCol - curCol - 1])
					continue;
				matrix[curRow][curCol] ^= matrix[curRow][maxCol - curCol - 1];
				matrix[curRow][maxCol - curCol - 1] ^= matrix[curRow][curCol];
				matrix[curRow][curCol] ^= matrix[curRow][maxCol - curCol - 1];
			}
		}
		//return matrix;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
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
