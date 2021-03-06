// 22. Generate Parentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	vector<string> res;

	void dfs(int left, int right, string s)
	{
		if (left == 0 && right == 0)
		{
			res.push_back(s);
			return;
		}
		if (left > 0)
		{
			dfs(left - 1, right, s + "(");
		}
		if (right > 0 && right > left)
		{
			dfs(left, right-1, s + ")");
		}
	}

	vector<string> generateParenthesis(int n) {
		dfs(n, n, "");
		return res;
	}
};

int main()
{
    cout << "Hello World!\n"; 
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
