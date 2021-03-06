// 72. Edit Distance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int size1 = word1.size();
		int size2 = word2.size();
		vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
		for (int i = 0; i < size1 + 1; i++)
		{
			dp[i][0] = i;
		}
		for (int i = 0; i < size2 + 1; i++)
		{
			dp[0][i] = i;
		}

		for (int i = 1; i < size1 + 1; i++)
		{
			for (int j = 1; j < size2 + 1; j++)
			{
				if (word1[i - 1] == word2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				}
			}
		}
		return dp[size1][size2];
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
