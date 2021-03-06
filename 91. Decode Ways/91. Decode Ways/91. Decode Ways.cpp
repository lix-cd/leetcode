// 91. Decode Ways.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int result;
	string s;

	void dfs(string::iterator iter)
	{
		if (iter == s.end())
		{
			result++;
			return;
		}
		if (*iter > '2')
		{
			dfs(iter + 1);
		}
		else if (*iter == '1')
		{
			dfs(iter + 1);
			if (iter + 2 <= s.end())
			{
				dfs(iter + 2);
			}
		}
		else if (*iter == '2')
		{
			if (iter + 1 !=s.end()&&*(iter + 1) <= '6')
			{
				dfs(iter + 1);
				if (iter + 2 <= s.end())
				{
					dfs(iter + 2);
				}
			}
			else
			{
				dfs(iter + 1);
			}
		}

	}

	int numDecodings(string s) {
		result = 0;
		this->s = s;
		auto iter = this->s.begin();
		dfs(iter);
		return result;
	}
};

int main()
{
	Solution sol;
	cout<<sol.numDecodings("12");
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
