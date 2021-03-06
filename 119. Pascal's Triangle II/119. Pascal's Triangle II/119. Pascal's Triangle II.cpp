// 119. Pascal's Triangle II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//	int fac(int n)
//	{
//		if (n == 1 || n == 0)
//			return 1;
//		else
//			return fac(n - 1)*n;
//	}
//
//	int combine(int n, int m)
//	{
//		return fac(n) / (fac(n - m)*fac(m));
//	}
//
//	vector<int> getRow(int rowIndex) {
//		vector<int> result;
//		int m = rowIndex;
//		for (int i = 0; i <= m; i++)
//		{
//			result.push_back(combine(m, i));
//		}
//		return result;
//	}
//};



int main()
{
	Solution sol;
	vector<int> result = sol.getRow(3);
	auto iter = result.begin();
	while (iter != result.end())
	{
		cout << *iter << endl;
		iter++;
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
