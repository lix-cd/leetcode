// 21. Merge Two Sorted Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

 class Solution {
 public:
	 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		 ListNode* resultHead = nullptr;
		 ListNode* resultCur = nullptr;
		 ListNode* temp = nullptr;

		 while (l1 && l2)
		 {
			 if (l1->val <= l2->val)
			 {
				 temp = (ListNode*)malloc(sizeof(ListNode));
				 temp->val = l1->val;
				 temp->next = nullptr;
				 l1 = l1->next;
			 }
			 else
			 {
				 temp = (ListNode*)malloc(sizeof(ListNode));
				 temp->val = l2->val;
				 temp->next = nullptr;
				 l2 = l2->next;
			 }
			 if (resultHead == nullptr)
			 {
				 resultHead = temp;
			 }
			 else
			 {
				 resultCur->next = temp;
			 }
			 resultCur = temp;
		 }
		 return resultHead->next;
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
