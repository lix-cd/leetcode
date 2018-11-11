// 折半查找.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int binarySearch(int a[],int size,int key)
{
	int low = 0, high = size;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < a[mid])
		{
			high = mid-1;
		}
		else if (key > a[mid])
		{
			low = mid+1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{

	int arr[10] = { 1,3,4,6,8,12,16,19,21,24 };
	cout<<binarySearch(arr, 10, 6);
   // std::cout << "Hello World!\n"; 
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
