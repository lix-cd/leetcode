// 122. Best Time to Buy and Sell Stock II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//int peak;
		int valley = INT_MAX;
		int curProfit = 0;
		bool poss = false;
		auto iter = prices.begin();
		while (iter != prices.end())
		{
			if (iter != prices.begin() && iter != prices.end() - 1)
			{
				if (*iter <= *(iter - 1) && *iter <= *(iter + 1)) //此为谷
				{
					valley = *iter;
					poss = true;
				}
				if (poss==true&&*iter >= *(iter - 1) && *iter >= *(iter + 1)) //此为峰
				{
					cout << *iter << "-" << valley<<"="<<*iter - valley << endl;
					curProfit += *iter - valley;
					poss = false;
				}
			}
			else if (iter == prices.begin() || poss == false)
			{
				if (iter == prices.end() - 1)
				{
					break;
				}
				if (*iter <= *(iter + 1)) //此为谷
				{
					valley = *iter;
					poss = true;
				}
			}
			else if (iter == prices.end() - 1) //最后一个元素
			{
				if (*iter >= *(iter - 1)) //此为峰
				{
					curProfit += *iter - valley;
					cout << *iter << "-" << valley << "=" << *iter - valley << endl;
					poss = false;
				}
			}
			iter++;
		}
		return curProfit;
	}
};

int main()
{
	vector<int> prices = { 5,2,3,2,6,6,2,9,1,0,7,4,5,0 };
	Solution sol;
	cout<<sol.maxProfit(prices);
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
