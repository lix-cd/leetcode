// 71. Simplify Path.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:

	string simplifyPath(string path) {
		stack<string> s;
		string result = "";

//		path.erase(remove(path.begin(), path.end(), '.'), path.end());


		string proccedPath;
		proccedPath.push_back(*(path.begin()));
		auto iter = path.begin() + 1;
		while (iter != path.end())
		{
			if (!(*iter == *(iter - 1) && *(iter - 1) == '/'))  //处理斜杠
			{
					proccedPath.push_back(*iter);
			}
			iter++;
		}

		cout << proccedPath << endl;

		iter = proccedPath.begin();
		string curPart;
		while (iter != proccedPath.end())
		{
			if (*iter == '.'&&*(iter + 1) != '.')
			{

			}
			else if ((iter + 1) != proccedPath.end() && *iter == '.'&&*(iter + 1) == '.') //遇到 ../的情况
			{
				if (!s.empty())
				{
					s.pop();
					iter += 1;
				}
			}
			else if ((iter + 1) != proccedPath.end() && *(iter + 1) == '/') //下一个字符为 / 的情况
			{
				curPart.push_back(*iter);
				s.push(curPart);
				curPart.clear();
			}
			else
			{
				curPart.push_back(*iter);
			}
			iter++;
		}

		while (!s.empty())
		{
			string cur = s.top();
			s.pop();
			result = cur + result;
		}

		string r;
		r += *(result.begin());
		auto iter1 = result.begin() + 1;
		while (iter1 != result.end())
		{
			if (!(*iter1 == *(iter1 - 1) && *(iter1 - 1) == '/'))  //处理斜杠
			{
				r.push_back(*iter1);
			}
			iter1++;
		}
		return r;
	}
};
int main()
{
	Solution sol;
	cout << sol.simplifyPath("/");
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
