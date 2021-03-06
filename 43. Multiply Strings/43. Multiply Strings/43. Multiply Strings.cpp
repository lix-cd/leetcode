// 43. Multiply Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		//map<int,vector<int>> result;
		string ret;
		stringstream ss;
		map<int,int> result;
		vector<int> vecRes;
		auto iter1 = num1.begin();
		auto iter2 = num2.begin();
		int carry = 0;
		while (iter1 != num1.end())
		{
			while (iter2 != num2.end())
			{
				result[iter1 - num1.begin() + iter2 - num2.begin()]
					=result[iter1 - num1.begin() + iter2 - num2.begin()]
					+(*iter1)*(*iter1); //逐位计算
				iter2++;
			}
			iter1++;
		}

		//拷贝到vector
		for (int i = 0;; i++)
		{
			if (result.find(i) == result.end()) //结束
			{
				break;
			}
			vecRes.push_back(result[i]);
		}


		reverse(vecRes.begin(), vecRes.end());


		auto iter = vecRes.begin();
		while (iter != vecRes.end())
		{
			cout << *iter << endl;
			iter++;
		}
		while (iter != vecRes.end()||carry!=0)
		{
			if (iter == vecRes.end())
			{
				vecRes.push_back(0);
			}
			*iter = *iter + carry;
			carry = *iter / 10;
			*iter = *iter % 10;
			iter++;
		}

		auto revIter = vecRes.rbegin();
		while (revIter != vecRes.rend())
		{
			ss << *revIter;
			revIter++;
		}
		ss >> ret;
		return ret;
	}
};

int main()
{
	Solution sol;
	cout<<sol.multiply("333", "333");
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
