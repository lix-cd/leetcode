// 50. Pow(x, n).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		double result = 1;
		if (x == 1)
		{
			return 1;
		}
		else if (x == -1)
		{
			if (n % 2 == 0)
			{
				return 1;
			}
			else
				return -1;
		}
		if (n < 0)
		{
			x = 1 / x;
			n = -n;
		}
		while (n--)
		{
			result *= x;
			if (result == 0)
			{
				break;
			}
		}

		return result;
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
