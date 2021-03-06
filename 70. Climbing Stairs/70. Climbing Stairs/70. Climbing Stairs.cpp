// 70. Climbing Stairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	map<int,int> m;

	int fabonacci(int n)
	{
		int result;
		map<int, int>::iterator valIter = m.find(n);
		if (valIter != m.end())
		{
			return valIter->second;
		}
		if (n == 0)
		{
			return 1;
		}
		if (n == 1)
		{
			return 1;
		}
		result = fabonacci(n - 1) + fabonacci(n - 2);
		m.insert(pair<int,int>(n,result));
		return result;
	}

	int climbStairs(int n) {
		return fabonacci(n);
	}
};

int main()
{
	Solution sol;
	int n;
	cin >> n;
	cout << sol.climbStairs(n);
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
