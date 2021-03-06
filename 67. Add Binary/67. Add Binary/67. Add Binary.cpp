// 67. Add Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		string::reverse_iterator itera = a.rbegin();
		string::reverse_iterator iterb = b.rbegin();
		string::reverse_iterator iterres = result.rbegin();
		int carry = 0;
		string app = "0";

		while (itera != a.rend() || iterb != b.rend())
		{
			if (itera == a.rend())
			{
				if (carry == 0 && *iterb == '0')
				{
					app = "0";
					carry = 0;
				}
				else if (carry == 0 && *iterb == '1')
				{
					app = "1";
					carry = 0;
				}
				else if (carry == 1 && *iterb == '1')
				{
					app = "0";
					carry = 1;
				}
				else if (carry == 1 && *iterb == '0')
				{
					app = "1";
					carry = 0;
				}
				iterb++;

			}
			else if (iterb == b.rend())
			{
				if (carry == 0 && *itera == '0')
				{
					app = "0";
					carry = 0;
				}
				else if (carry == 0 && *itera == '1')
				{
					app = "1";
					carry = 0;
				}
				else if (carry == 1 && *itera == '1')
				{
					app = "0";
					carry = 1;
				}
				else if (carry == 1 && *itera == '0')
				{
					app = "1";
					carry = 0;
				}
				itera++;
			}

			else
			{
				if (carry == 0 && *itera == '0'&& *iterb == '0')
				{
					app = "0";
					carry = 0;
				}
				else if (carry == 0 && *itera == '0'&& *iterb == '1')
				{
					app = "1";
					carry = 0;
				}
				else if (carry == 0 && *itera == '1'&& *iterb == '0')
				{
					app = "1";
					carry = 0;
				}
				else if (carry == 0 && *itera == '1'&& *iterb == '1')
				{
					app = "0";
					carry = 1;
				}
				else if (carry == 1 && *itera == '0'&& *iterb == '0')
				{
					app = "1";
					carry = 0;
				}
				else if (carry == 1 && *itera == '0'&& *iterb == '1')
				{
					app = "0";
					carry = 1;
				}
				else if (carry == 1 && *itera == '1'&& *iterb == '0')
				{
					app = "0";
					carry = 1;
				}
				else if (carry == 1 && *itera == '1'&& *iterb == '1')
				{
					app = "1";
					carry = 1;
				}
				itera++;
				iterb++;
			}
			result = app + result;

			if (itera == a.rend() && iterb == b.rend())
			{
				if (carry == 1)
				{
					result = "1" + result;
				}
			}

			//iterres++;
		}
		return result;
	}
};

int main()
{
	Solution sol;
	cout << sol.addBinary("11", "1");
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
