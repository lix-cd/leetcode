// 60. Permutation Sequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:

	int n;
	vector<string> resultSet;

	void dfs(string str)
	{
		if (str.size() == n)
		{
			resultSet.push_back(str);
			return;
		}
		for (int index = 1; index <= n; index++)
		{
			char indexChar = '0' + index;
			if (str.find(indexChar)!=-1) //找到
			{
				continue;
			}
			else  
			{
				dfs(str + indexChar);
			}
		}
	}

	string getPermutation(int n, int k) {
		this->n = n;
		dfs(string());
		sort(resultSet.begin(), resultSet.end());
		cout << resultSet.size()<<endl;
		auto iter = resultSet.begin();
		return resultSet[k-1];
	}
};

int main()
{
	Solution sol;
	cout << sol.getPermutation(9, 278082)<<endl;
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
