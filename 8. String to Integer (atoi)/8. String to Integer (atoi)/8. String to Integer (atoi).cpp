// 8. String to Integer (atoi).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int result = 0;
		string::iterator iter = str.begin();
		bool postiveFlag = true;
		bool signMerged = false;
		bool started = false;
		while (iter != str.end())
		{
			if (signMerged && (*iter == '-' || *iter == '+') && started)
			{
				goto label;
			}
			if (signMerged && (*iter == '-' || *iter == '+'))
			{
				return 0;
			}
			if (*iter == '-')
			{
				postiveFlag = false;
				signMerged = true;
				started = true;
			}
			else if (*iter == '+')
			{
				signMerged = true;
				started = true;
			}
			else if (*iter >= '0'&&*iter <= '9')
			{
				started = true;
				signMerged = true;
				//int prevResult = result;
				//result = (result * 10 + (*iter - '0'));

				if ((INT_MAX- (*iter - '0'))/10<result)
				{
					if (postiveFlag)
					{
						return INT_MAX;
					}
					else
					{
						return INT_MIN;
					}
				}
				//result = prevResult;
				result = result * 10 + (*iter - '0');
			}
			else if (*iter == ' ')
			{
				if (started)
				{
					goto label;
				}
				iter++;
				continue;
			}
			else
			{
				break;
			}
			iter++;
		}
		label:
		if (!postiveFlag)
		{
			result = -result;
		}
		return result;
	}
};

int main()
{
	Solution sol;
	cout<<sol.myAtoi("-5-");
    //mstd::cout << "Hello World!\n"; 
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
