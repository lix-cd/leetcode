// 14. Longest Common Prefix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "string"
#include "vector"
#include "sstream"
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
		{
			return "";
		}
		string result = "";
		vector<string>::iterator iter = strs.begin();
		string::iterator shortestStringIter;
		int shortestStringSize = INT_MAX;
		while (iter != strs.end())
		{
			if (iter->size() < shortestStringSize)  //取最小字符串长度
			{
				shortestStringSize = iter->size();
			}
			iter++;
		}

		if (shortestStringSize == 0)
		{
			return "";
		}

		iter = strs.begin();

		int index = 0;
		
		while (index < shortestStringSize)  //外层循环字符
		{
			iter = strs.begin();
			bool dup = true;
			while (iter != strs.end()) //内层循环字符串vector
			{
				if ((*iter)[index] != (*(strs.begin()))[index]) //找到当前元素不重复
				{
				    dup = false;
				}
				iter++;
			}
			if (dup)
			{
				result += (*(strs.begin()))[index]; 
			}
			else
			{
				break;
			}
			index++;
		}

		return result;
	}
};

int main()
{
	vector<string> strs;
	strs.push_back("aca");
	strs.push_back("cba");
	//strs.push_back("flight");
	Solution sol;
    std::cout << sol.longestCommonPrefix(strs);
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
