// 28. Implement strStr().cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		if (haystack == ""&&needle == "")
//			return 0;
//		if (needle.size() > haystack.size())
//			return -1;
//		if (haystack == needle)
//			return 0;
//		string::iterator iter = haystack.begin();
//		string::iterator needleIter = needle.begin();
//		int pos = 0;
//		while (iter != haystack.end())
//		{
//			while (needleIter != needle.end())
//			{
//				string::iterator curIter = iter;
//				if (*iter == *needleIter)
//				{
//					curIter++;
//					needleIter++;
//				}
//				else
//				{
//					needleIter = needle.begin();
//					break;
//				}
//			}
//			if (needleIter == needle.end()) //找到
//			{
//				break;
//			}
//			iter++;
//			pos++;
//		}
//		if (iter == haystack.end())
//		{
//			return -1;
//		}
//		return pos;
//	}
//};

class Solution {
public:
    int strStr(string haystack, string needle) {
		if (needle.size() > haystack.size())
		{
			return -1;
		}
		auto iter = haystack.begin();
		while (iter != haystack.end() - needle.size() +1)
		{
			if (string(iter, iter + needle.size()) == needle)
				return iter - haystack.begin();
			iter++;
		}
		return -1;
    }
};

int main()
{
	Solution sol;
	cout<<sol.strStr("abb", "abaaa");
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
