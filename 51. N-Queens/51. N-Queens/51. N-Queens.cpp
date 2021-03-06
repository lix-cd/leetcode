// 51. N-Queens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int n;
	vector<vector<string>> result;

	string generateCurRowStr(int queen)
	{
		string result = "";
		for (int i = 0; i < n; i++)
		{
			if (i == queen)
			{
				result.push_back('Q');
			}
			else 
			{
				result.push_back('.');
			}
		}
		return result;
	}
	void dfs(vector<bool> colPlaced, vector<bool> leftSlashPlaced, vector<bool> rightSlashPlaced, int curRow, vector<string> curMap)
	{
		vector<bool> newColPlaced;
		vector<bool> newLeftSlashPlaced;
		vector<bool> newRightSlashPlaced;
		if (curRow == n)
		{
			result.push_back(curMap);
		}
		for (int i = 0; i < n; i++)
		{
			cout << "i-curRow+ n :" << i - curRow + n << endl;
			cout << "i+curRow :" << i + curRow << endl;
			if (colPlaced[i] == false && leftSlashPlaced[i - curRow + n] == false && rightSlashPlaced[i + curRow] == false)
			{
				newLeftSlashPlaced = leftSlashPlaced;
				newLeftSlashPlaced[i - curRow + n] = true;
				newRightSlashPlaced = rightSlashPlaced;
				newRightSlashPlaced[i + curRow] == true;
				newColPlaced = colPlaced;
				newColPlaced[i] = true;
				string str = generateCurRowStr(i);
				vector<string> newCurMap = curMap;
				newCurMap.push_back(str);
				dfs(newColPlaced, newLeftSlashPlaced, newRightSlashPlaced, curRow + 1, newCurMap);
			}
		}
	}

	vector<vector<string>> solveNQueens(int n) {
		this->n = n;
		vector<bool> placed = vector<bool>(n, false);
		vector<bool> leftSlashPlaced = vector<bool>(2 * n + 1, false);
		vector<bool> rightSlashPlaced = vector<bool>(2 * n + 1, false);
		dfs(placed, leftSlashPlaced, rightSlashPlaced, 0, vector<string>());
		return result;
	}
};

int main()
{
	Solution sol;
	sol.solveNQueens(4);
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
