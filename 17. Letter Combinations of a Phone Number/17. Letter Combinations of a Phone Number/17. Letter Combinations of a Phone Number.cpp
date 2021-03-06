// 17. Letter Combinations of a Phone Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	const vector<char> two = { 'a','b','c' };
	const vector<char> three = { 'd','e','f' };
	const vector<char> four = { 'g','h','i' };
	const vector<char> five = { 'j','k','l' };
	const vector<char> six = { 'm','n','o' };
	const vector<char> seven = { 'p','q','r','s' };
	const vector<char> eight = { 't','u','v' };
	const vector<char> nine = { 'w','x','y','z' };
	vector<string> result;
	string digits;

	void dfs(string::iterator iter,string str)
	{
		if (iter == digits.end())
		{
			result.push_back(str);
			return;
		}
		vector<char> button;
		switch (*iter)
		{
		case '2':
			button = two;
			break;
		case '3':
			button = three;
			break;
		case '4':
			button = four;
			break;
		case '5':
			button = five;
			break;
		case '6':
			button = six;
			break;
		case '7':
			button = seven;
			break;
		case '8':
			button = eight;
			break;
		case '9':
			button = nine;
			break;
		default:
			break;
		}
		
		vector<char>::iterator letterIter = button.begin();

		while (letterIter != button.end())
		{
			dfs(iter+1,str+*letterIter);
			letterIter++;
		}

	}

	vector<string> letterCombinations(string digits) {
		if (digits == "")
		{
			return vector<string>();
		}
		this->digits = digits;
		dfs(this->digits.begin(),string());
		return result;
	}
};
int main()
{
	Solution sol;
	vector<string> result = sol.letterCombinations("23");
	auto iter = result.begin();
	while (iter != result.end())
	{
		cout << *iter<<" ";
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
