// 19. Remove Nth Node From End of List.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* curPtr = head;
		ListNode* rearPtr = head;
		ListNode* deleteNodePtr = head;

		//do this one in one pass
		while (rearPtr != nullptr) //当后一个指针到达末尾的时候
		{
			if (n != 0) //rearPtr先走n步
			{
				rearPtr = rearPtr->next;
				n--;
				if (rearPtr == nullptr)  //走到末尾，则为删除第一个元素
				{
					return head->next;
				}
				continue;
			}
			curPtr = curPtr->next;
			rearPtr = rearPtr->next;
		}

		deleteNodePtr = curPtr->next;
		curPtr->next = deleteNodePtr -> next;
		free(deleteNodePtr);


		return head;
	}
};

int main()
{

	int n;
	int val;
	int deleteElem;
	cin >> n;
	ListNode* head = nullptr;
	ListNode* temp = nullptr;
	ListNode* last = nullptr;
	ListNode* cur = nullptr;

	while (n--)  //读链表
	{
		cin >> val;
		temp = (ListNode*)malloc(sizeof(ListNode));
		temp->val = val;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
		}
		else
		{
			last->next = temp;
		}
		last = temp;
	}
	cin >> deleteElem;
	Solution sol;
	head = sol.removeNthFromEnd(head, deleteElem);
	if (!head)
	{
		cout << "NULL";
	}
	cur = head;
	while (cur)
	{
		cout << cur->val<<" ";
		cur = cur->next;
	}
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
