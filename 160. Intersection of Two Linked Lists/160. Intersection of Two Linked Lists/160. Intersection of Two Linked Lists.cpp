// 160. Intersection of Two Linked Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 class Solution {
 public:
	 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		 int lengthA = 0;
		 int lengthB = 0;
		 int differ;
		 ListNode* curA = headA;
		 ListNode* curB = headB;
		 while (curA != nullptr)
		 {
			 curA = curA->next;
			 lengthA++;
		 }
		 while (curB != nullptr)
		 {
			 curB = curB->next;
			 lengthB++;
		 }
		 curA = headA;
		 curB = headB;
		 if (lengthA > lengthB)
		 {
			 differ = lengthA - lengthB;
			 while (differ--)
			 {
				 curA = curA->next;
			 }
		 }
		 else
		 {
			 differ = lengthB - lengthA;
			 while (differ--)
			 {
				 curB = curB->next;
			 }
		 }
		 while (curA || curB)
		 {
			 if (curA == curB)
			 {
				 return curA;
			 }
			 curA = curA->next;
			 curB = curB->next;
		 }
		 return nullptr;
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
