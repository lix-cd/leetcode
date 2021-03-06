// 36. Valid Sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		set<char> row0;
		set<char> row1;
		set<char> row2;
		set<char> row3;
		set<char> row4;
		set<char> row5;
		set<char> row6;
		set<char> row7;
		set<char> row8;

		set<char> col0;
		set<char> col1;
		set<char> col2;
		set<char> col3;
		set<char> col4;
		set<char> col5;
		set<char> col6;
		set<char> col7;
		set<char> col8;

		set<char> sub0;
		set<char> sub1;
		set<char> sub2;
		set<char> sub3;
		set<char> sub4;
		set<char> sub5;
		set<char> sub6;
		set<char> sub7;
		set<char> sub8;

		vector<vector<char>>::iterator rowIter = board.begin();
		vector<char>::iterator colIter;

		int curRow = 0;
		int curCol = 0;

		while (rowIter != board.end())
		{
			colIter = rowIter->begin();
			while (colIter != rowIter->end())
			{
				cout << curRow << endl;
				cout << curCol << endl;
				curRow = rowIter - board.begin();
				curCol = colIter - rowIter->begin();

				if (*colIter == '.')
					continue;

				switch (curRow)
				{
				case 0:
					if (row0.count(*colIter))
						goto label;
					row0.insert(*colIter);
					break;
				case 1:
					if (row1.count(*colIter))
						goto label;
					row1.insert(*colIter);
					break;
				case 2:
					if (row2.count(*colIter))
						goto label;
					row2.insert(*colIter);
					break;
				case 3:
					if (row3.count(*colIter))
						goto label;
					row3.insert(*colIter);
					break;
				case 4:
					if (row4.count(*colIter))
						goto label;
					row4.insert(*colIter);
					break;
				case 5:
					if (row5.count(*colIter))
						goto label;
					row5.insert(*colIter);
					break;
				case 6:
					if (row6.count(*colIter))
						goto label;
					row5.insert(*colIter);
					break;
				case 7:
					if (row7.count(*colIter))
						goto label;
					row7.insert(*colIter);
					break;
				case 8:
					if (row8.count(*colIter))
						goto label;
					row8.insert(*colIter);
					break;
				default:
					break;
				}

				switch (curCol)
				{
				case 0:
					col0.insert(*colIter);
					if (col0.count(*colIter))
						goto label;
					break;
				case 1:
					if (col1.count(*colIter))
						goto label;
					col1.insert(*colIter);
					break;
				case 2:
					if (col2.count(*colIter))
						goto label;
					col2.insert(*colIter);
					break;
				case 3:
					if (col3.count(*colIter))
						goto label;
					col3.insert(*colIter);
					break;
				case 4:
					if (col4.count(*colIter))
						goto label;
					col4.insert(*colIter);
					break;
				case 5:
					if (col5.count(*colIter))
						goto label;
					col5.insert(*colIter);
					break;
				case 6:
					if (col6.count(*colIter))
						goto label;
					col6.insert(*colIter);
					break;
				case 7:
					if (col7.count(*colIter))
						goto label;
					col7.insert(*colIter);
					break;
				case 8:
					if (col8.count(*colIter))
						goto label;
					col8.insert(*colIter);
					break;
				default:
					break;
				}

				if (curRow < 3 && curCol < 3)
				{
					if (sub0.count(*colIter))
						goto label;
					sub0.insert(*colIter);
					//break;
				}
				else if (curRow < 3 && curCol < 6)
				{
					if (sub1.count(*colIter))
						goto label;
					sub1.insert(*colIter);
					//break;
				}
				else if (curRow < 3 && curCol < 9)
				{
					if (sub2.count(*colIter))
						goto label;
					sub2.insert(*colIter);
					//break;
				}
				else if (curRow < 6 && curCol < 3)
				{
					if (sub3.count(*colIter))
						goto label;
					sub3.insert(*colIter);
					//break;
				}
				else if (curRow < 6 && curCol < 6)
				{
					if (sub4.count(*colIter))
						goto label;
					sub4.insert(*colIter);
					//break;
				}
				else if (curRow < 6 && curCol < 9)
				{
					if (sub5.count(*colIter))
						goto label;
					sub5.insert(*colIter);
					//break;
				}
				else if (curRow < 9 && curCol < 3)
				{
					if (sub6.count(*colIter))
						goto label;
					sub6.insert(*colIter);
					//break;
				}
				else if (curRow < 9 && curCol < 6)
				{
					if (sub7.count(*colIter))
						goto label;
					sub7.insert(*colIter);
					//break;
				}
				else if (curRow < 9 && curCol < 9)
				{
					if (sub8.count(*colIter))
						goto label;
					sub8.insert(*colIter);
					//break;
				}
				curCol++;
				colIter++;
			}
			curRow++;
			rowIter++;
		}
		return true;
	label:
		return false;

	}
};

int main()
{
	vector<vector<char>> rows;
	vector<char> cols;
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{

		}
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
