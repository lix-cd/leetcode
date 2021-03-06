// 61. Rotate List.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* temp;
		ListNode* cur = head;
		ListNode* last;
		temp = head;

		while (cur)
		{
			last = cur;
			cur = cur->next;
			if (k == 0)
			{
				//last->next = nullptr;
				head = last;
			}
			//cur = cur->next;
			k--;
			if (cur == nullptr)
			{
				last ->next = temp;
			}
		}
		return head;
	}
};

int main()
{
	//创建链表
	ListNode* temp = nullptr;
	ListNode* head = nullptr;
	ListNode* cur = nullptr;
	int n;
	cin >> n;
	while (n--)
	{
		temp = (ListNode*)malloc(sizeof(ListNode));
		temp->next = nullptr;
		cin >> temp->val;
		if (head == nullptr)
		{
			head = temp;
			cur = head;
		}
		else
		{
			cur->next = temp;
		}
		cur = temp;
	}

	Solution sol;
	head = sol.rotateRight(head, 2);
	temp = head;
	while (temp)
	{
		cout << temp->val << ' ';
		temp = temp->next;
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
