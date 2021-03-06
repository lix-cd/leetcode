// 5. Longest Palindromic Substring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

	int max;
	string curMaxPalString;
	string s;

	bool judgePalindromic(string s)
	{
		string s1 = s;
		reverse(s1.begin(), s1.end());
		if (s1 == s)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void dfs(string::iterator start,string::iterator end)
	{
		string cur = string(start, end);
		if (judgePalindromic(cur))
		{
			if (cur.size()>max)
			{
				max = cur.size(); //更新当前的最大字符串长度标记
				curMaxPalString = string(start, end);
			}
			if(start!=s.begin())
				dfs(start - 1, end); // 向左扩散
			if(end!=s.end())
				dfs(start, end + 1); //向右扩散
			if (start != s.begin() && end != s.end())
				dfs(start - 1, end + 1);  //两端扩散
		}
		else
			return;
	}

	string longestPalindrome(string s) {
		max = 0;
		this->s = s;
		string::iterator iter = this->s.begin();
		while (iter != this->s.end())
		{
			dfs(iter, iter+1);
			iter++;
		}
		return curMaxPalString;
	}
};

int main()
{
	Solution sol;
	cout << "answer：" <<endl<<sol.longestPalindrome("aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffg") << endl;
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
