// 29. Divide Two Integers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution {
public:

	int result;

	void handleDivede(int dividend, int divisor)
	{
		if (dividend!=INT_MIN&&divisor > -dividend) 
			return;

		int curResult = 1;
		int temp = -divisor;

		while (temp >= dividend)
		{
			if (temp +temp <=temp&&temp << 1 >= dividend)
			{
				temp += temp; 
				curResult <<= 1; 
			}
			else
				break;
		}

		result -= curResult;

		handleDivede(dividend - temp, divisor);
	}

	int divide(int dividend, int divisor) {
		result = 0;

		if (divisor == INT_MIN)
		{
			if (dividend == INT_MIN)
			{
				return 1;
			}
			return 0;
		}

		if (divisor == 0)   //OVERFLOW
		{
			return INT_MAX;
		}
		bool positiveFlag = true;
		int temp = 0;
		if (dividend >> 31 != divisor >> 31) 
		{
			positiveFlag = false;
		}
		if (dividend > 0)
		{
			dividend = -dividend;
		}
		divisor = abs(divisor);
		
		handleDivede(dividend, divisor);

		if (positiveFlag == true)
		{
			if (result == INT_MIN)
			{
				return INT_MAX;
			}
			result = -result;
		}
		return result;
	}
};

int main()
{
	Solution sol;
	//cout << -2147483647 - 1 << endl;
	cout << sol.divide(INT_MIN, INT_MIN);
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
