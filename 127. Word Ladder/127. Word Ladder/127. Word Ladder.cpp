// 127. Word Ladder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct CurTrans
{
	int times;
	string word;
};

class Solution {
public:

	bool judgeCanBeTransed(string s1,string s2)
	{
		auto iter1 = s1.begin();
		auto iter2 = s2.begin();
		int count = 2;
		while (iter1 != s1.end())
		{
			if (*iter1 == *iter2)
			{
				count--;
			}
			iter1++;
			iter2++;
		}
		if (count)
			return true;
		else
			return false;
	}

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		queue<CurTrans> q;
		CurTrans c;
		c.word = beginWord;
		c.times = 0;
		q.push(c);
		while (!q.empty())
		{
			c = q.front();
			q.pop();
			if (c.word == endWord)
				return c.times;
			auto iter = wordList.begin();
			while (iter != wordList.end())
			{
				if (judgeCanBeTransed(*iter, c.word))
				{
					c.times += 1;
					c.word = *iter;
					q.push(c);
				}
				iter++;
			}
		}
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
