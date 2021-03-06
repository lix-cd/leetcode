// 12. Integer to Roman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string result;

		int i = 0, v = 0, x = 0, l = 0, c = 0, d = 0, m = 0;
		int four = 0, nine = 0, fourZero = 0, nineZero = 0, fourZeroZero = 0, nineZeroZero = 0;
		/*
		Symbol       Value
		I             1
		V             5
		X             10
		L             50
		C             100
		D             500
		M             1000
		*/

		m = num / 1000;
		num %= 1000;

		nineZeroZero = num / 900;
		num %= 900;

		d = num / 500;
		num %= 500;

		fourZeroZero = num / 400;
		num %= 400;

		c = num / 100;
		num %= 100;

		nineZero = num / 90;
		num %= 90;

		l = num / 50;
		num %= 50;

		fourZero = num / 40;
		num %= 40;

		x = num / 10;
		num %= 10;

		nine = num / 9;
		num %= 9;

		v = num / 5;
		num %= 5;

		four = num / 4;
		num %= 4;

		i = num;

		while (m--)
		{
			result += "M";
		}
		while (nineZeroZero--)
		{
			result += "CM";
		}
		while (d--)
		{
			result += "D";
		}
		while (fourZeroZero--)
		{
			result += "CD";
		}
		while (c--)
		{
			result += "C";
		}
		while (nineZero--)
		{
			result += "XC";
		}
		while (l--)
		{
			result += "L";
		}
		while (fourZero--)
		{
			result += "XL";
		}
		while (x--)
		{
			result += "X";
		}
		while (nine--)
		{
			result += "IX";
		}
		while (v--)
		{
			result += "V";
		}
		while (four--)
		{
			result += "IV";
		}
		while (i--)
		{
			result += "I";
		}
		return result;
	}
};

int main()
{
	Solution sol;
	cout<<sol.intToRoman(3);
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
