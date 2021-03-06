// 165. Compare Version Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> ver1;
		vector<int> ver2;
		auto iter1 = version1.begin();
		auto iter2 = version2.begin();
		string curPart = "";
		while (iter1 != version1.end())
		{
			if (*iter1 == '.' || iter1 == version1.end())
			{
				ver1.push_back(stoi(curPart));
				curPart = "";
			}
			else
			{
				curPart += *iter1;
			}
			iter1++;
		}
		ver1.push_back(stoi(curPart));

		curPart = "";
		while (iter2 != version2.end())
		{
			if (*iter2 == '.' || iter2 == version2.end())
			{
				ver2.push_back(stoi(curPart));
				curPart = "";
			}
			else
			{
				curPart += *iter2;
			}
			iter2++;
		}
		ver2.push_back(stoi(curPart));

		auto vecIter1 = ver1.begin();
		auto vecIter2 = ver2.begin();
		while (vecIter1 != ver1.end() || vecIter2 != ver2.end())
		{
			if (vecIter1 == ver1.end())
			{
				if (*vecIter2 > 0)
				{
					return -1;
				}
				else
				{
					vecIter2++;
					continue;
				}
			}
			if (vecIter2 == ver2.end())
			{
				if (*vecIter1 > 0)
				{
					return 1;
				}
				else
				{
					vecIter1++;
					continue;
				}
			}
			if (*vecIter1 > *vecIter2)
			{
				return 1;
			}
			else if(*vecIter1 < *vecIter2)
			{
				return -1;
			}
			else
			{
				vecIter1++;
				vecIter2++;
				continue;
			}
		}
		return 0;
	}
};

int main()
{
	Solution sol;
	cout << (sol.compareVersion("1", "1.1")) << endl;
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
