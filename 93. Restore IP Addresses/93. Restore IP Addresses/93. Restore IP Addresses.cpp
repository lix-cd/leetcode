// 93. Restore IP Addresses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:

	string s;
	set<string> result;

	void dfs(int dotLeft,string curPart,string::iterator cur,string curIp)
	{
		if (cur == s.end()&&dotLeft==0) //到达末尾
		{
			string add = curIp + curPart;
			cout << "add: " << add << endl;
			if(*(add.end() - 1)!='.')
				if(*(curPart.begin()) != '0'||curPart == "0")
				result.insert(add);
			return;
		}
		if (cur == s.end() && dotLeft != 0)
		{
			return;
		}
		curPart = curPart + *cur;  //当前字符
		if (stoi(curPart) < 0 || stoi(curPart)>255) //不合法
			return;

		if (dotLeft != 0) //还有点
		{
			if (curPart != "0")
			{
				dfs(dotLeft, curPart, cur + 1, curIp);//当前结果，不加点的
				cout << curPart << endl;
				curIp += curPart + ".";  //当前结果 加点的
				dfs(dotLeft - 1, "", cur + 1, curIp);
			}
			else
			{
				cout << curPart << endl;
				curIp += curPart + ".";  //当前结果 加点的
				dfs(dotLeft - 1, "", cur + 1, curIp);
			}
		}
		else //没有点了
		{
			dfs(dotLeft, curPart, cur + 1, curIp);//当前结果，不加点的
		}
	}

	vector<string> restoreIpAddresses(string s) {
		this->s = s;
		dfs(3, "", this->s.begin(), "");
		vector<string> ret;
		ret.assign(result.begin(), result.end());
		return ret;
	}
};

int main()
{
	string input = "010010";
	vector<string> result;
	Solution sol;
	result = sol.restoreIpAddresses(input);
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
