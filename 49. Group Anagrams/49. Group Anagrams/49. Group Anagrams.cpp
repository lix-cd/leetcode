// 49. Group Anagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		vector<vector<string>> result;
		auto iter = strs.begin();
		map<string, vector<string>> m;
		while (iter != strs.end())
		{
			string temp = *iter;
			sort(temp.begin(), temp.end());
			if (m.find(temp) == m.end()) //找不到
			{
				auto cur = vector<string>();
				cur.push_back(*iter);
				m[temp] = cur;
			}
			else
			{
				m[temp].push_back(*iter);
			}
			iter++;
		}

		auto mapIter = m.begin();
		while (mapIter != m.end())
		{
			result.push_back(mapIter->second);
			mapIter++;
		}
		return result;

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
