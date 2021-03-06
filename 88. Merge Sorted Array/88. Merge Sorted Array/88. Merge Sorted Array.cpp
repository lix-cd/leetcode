// 88. Merge Sorted Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = 0;
		int cur = 0;
		while (i<n)
		{
			while (cur < nums1.size())
			{
				if (nums2[i] >= nums1[cur] && nums2[i] < nums1[cur])
				{
					nums1.insert(nums1.begin() + cur, nums2[i]);
					cur++;
					nums1.pop_back();
				}
				cur++;
			}
			i++;
		}
	}
};

int main()
{
	Solution sol;
	int arr1[] = { 1,2,3,0,0,0 };
	int arr2[] = { 2,5,6};
	vector<int> num1(arr1, arr1 + 5);
	vector<int> num2(arr2, arr1 + 2);

	sol.merge(num1, 3, num2, 3);
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
