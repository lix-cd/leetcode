// 73. Set Matrix Zeroes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//constant space solution
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<int> rowZeros;
		vector<int> colZeros;
		for (size_t row = 0; row < rows; row++)
		{
			for (size_t col = 0; col < cols; col++)
			{
				if (!matrix[row][col])
				{
					rowZeros.push_back(row);
					colZeros.push_back(col);
				}
			}
		}

		for (size_t row = 0; row < rows; row++)
		{
			for (size_t col = 0; col < cols; col++)
			{
				if (find(rowZeros.begin(), rowZeros.end(), row)!=rowZeros.end()|| find(colZeros.begin(), colZeros.end(), col) != colZeros.end())
				{
					matrix[row][col] = 0;
				}
			}
		}

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
