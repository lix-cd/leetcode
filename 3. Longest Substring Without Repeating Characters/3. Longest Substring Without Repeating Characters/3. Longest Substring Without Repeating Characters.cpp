// 3. Longest Substring Without Repeating Characters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		string::iterator iter = s.begin();
		string::iterator curIter;
		set<char> st;
		int max=0;
		while (iter != s.end())
		{
			curIter = iter;
			st.clear();
			while (curIter != s.end()) //找到
			{
				if (st.find(*curIter) != st.end())
				{
					break;
				}
				st.insert(*curIter);
				curIter++;
			}
			if (st.size() > max)
			{
				max = st.size();
			}
			iter++;
		}
		return max;
	}
};

int main()
{
	Solution sol;
	cout<<sol.lengthOfLongestSubstring("abcabcbb");
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
