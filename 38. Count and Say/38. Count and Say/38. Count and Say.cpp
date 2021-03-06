// 38. Count and Say.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Solution {
public:
	string result[30];
	stringstream ss;

	void generateResult(int n)
	{
		if (n == 30)
			return;
		string::iterator iter = result[n-1].begin();
		char cur = *iter;
		int count = 0;
		string temp;
		while (true)
		{
			temp = "";
			if (iter == result[n - 1].end() ||*iter != cur) 
			{
				ss.clear();
				ss << count << cur;
				ss>>temp;
				result[n] += temp;
				count = 1;
				if (iter == result[n - 1].end()) //已经到达末尾的情况
				{
					break;
				}
			}
			else
			{
				count++;
			}
			cur = *iter;
			iter++;
		}
		generateResult(n + 1);
	}

	string countAndSay(int n) {
		result[0] = "1";
		result[1] = "11";
		generateResult(2);
		return result[n - 1];
	}
};

int main()
{
	Solution sol;

	cout<<sol.countAndSay(5);
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
