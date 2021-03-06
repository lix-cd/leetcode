// 56. Merge Intervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
 bool operator< (Interval left, Interval right)
 {
	 if (left.start < right.start)
		 return true;
	 else return false;
 }

 class Solution {
 public:
	 vector<Interval> merge(vector<Interval>& intervals) {
		 if (intervals.empty())
			 return vector<Interval>();
		 vector<Interval> result;
		 sort(intervals.begin(), intervals.end());
		 int startInterval = INT_MAX;
		 int endInterval = INT_MIN;
		 auto iter = intervals.begin();
		 while (true)
		 {
			 startInterval = iter->start; //设置最小值
			 Interval curInterval = 
			 while ((iter + 1) != intervals.end() && iter->end >= (iter + 1)->start) //判断和下一个是否连续
				 iter++;
			 //endInterval = iter->end;
			 endInterval = iter->end > (iter - 1)->end? iter->end: (iter - 1)->end;
			 result.push_back(Interval(startInterval, endInterval));
			 iter++;
			 if (iter == intervals.end())
				 break;
		 }
		 return result;
	 }
 };

int main()
{
	int n;
	int start, end;
	vector<Interval> input;
	cin >> n;
	while (n--)
	{
		Interval cur;
		cin >> start;
		cin >> end;
		input.push_back(Interval(start, end));
	}
	Solution sol;
	sol.merge(input);
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
