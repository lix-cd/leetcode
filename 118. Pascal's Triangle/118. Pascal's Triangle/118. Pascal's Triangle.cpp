// 118. Pascal's Triangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		if (numRows == 0)
		{
			return {};
		}
		result.push_back({ 1 });
		for (size_t row = 1; row < numRows; row++)
		{
			vector<int> curCol;
			for (size_t col = 0; col <= row; col++)
			{
				if (col == 0 || col == row)
				{
					curCol.push_back(1);
				}
				else
				{
					curCol.push_back(result[row - 1][col - 1] + result[row - 1][col]);
				}
			}
			result.push_back(curCol);
		}
		return result;
	}
};

int main()
{
	Solution sol;
	auto result = sol.generate(5);
	auto rowIter = result.begin();
	while (rowIter != result.end())
	{
		auto colIter = (*rowIter).begin();
		while (colIter != (*rowIter).end())
		{
			cout << *colIter << " ";
			colIter++;
		}
		cout << endl;
		rowIter++;
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
