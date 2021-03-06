// 187. Repeated DNA Sequences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		if (s == "" || s.size() <= 10)
			return {};
		vector<string> result;
		set<string> st;
		set<string> resultSet;
		auto iter = s.begin();
		while (iter != s.end() - 9)
		{
			if (st.find(string(iter, iter + 10)) != st.end())
			{
				resultSet.insert(string(iter, iter + 10));
			}
			else
			{
				st.insert(string(iter, iter + 10));
			}
			iter++;
		}
		result.assign(resultSet.begin(), resultSet.end());
		return result;
	}
};

int main()
{
	Solution sol;
	vector<string> result;
	result = sol.findRepeatedDnaSequences("AAAAAAAAAAAA");
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
