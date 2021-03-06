// 2. Add Two Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
  */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


  //class Solution {
  //public:
	 // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//  int carry = 0;
		//  ListNode* resultHead = NULL;
		//  ListNode *cur = resultHead;
		//  ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
		//  while (l1 || l2)
		//  {
		//	  if (!l1)
		//	  {
		//		  temp->val = (l2->val + carry) % 10;
		//		  temp->next = NULL;
		//		  if (l2->val + carry >= 10)
		//		  {
		//			  carry = 1;
		//		  }
		//		  else
		//		  {
		//			  carry = 0;
		//		  }
		//		  l2 = l2->next;

		//	  }
		//	  if (!l2)
		//	  {
		//		  temp->val = (l2->val + carry) % 10;
		//		  temp->next = NULL;
		//		  if (l1->val + carry >= 10)
		//		  {
		//			  carry = 1;
		//		  }
		//		  else
		//		  {
		//			  carry = 0;
		//		  }
		//		  l1 = l1->next;
		//	  }

		//	  if (l1&&l2)
		//	  {
		//		  temp->val = (l1->val + l2->val + carry) % 10;
		//		  temp->next = NULL;
		//		  if (l1->val + l2->val + carry >= 10)
		//		  {
		//			  carry = 1;
		//		  }
		//		  else
		//		  {
		//			  carry = 0;
		//		  }
		//		  l1 = l1->next;
		//		  l2 = l2->next;
		//	  }
		//  }

		//  if (!resultHead)
		//  {
		//	  resultHead = temp;
		//  }
		//  else
		//  {
		//	  cur->next = temp;
		//  }

		//  cur = cur->next;

		//  return resultHead;
	 // }
  //};

  class Solution {
  public:
	  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		  ListNode* l1cur = l1;
		  ListNode* l2cur = l2;
		  ListNode* result = nullptr;
		  ListNode* resultCur;
		  int carry = 0;
		  while (l1cur || l2cur)
		  {
			  ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
			  if (l1cur&&l2cur)
			  {
				  temp->val = (l1cur->val + l2cur->val + carry) % 10;
				  carry = (l1cur->val + l2cur->val + carry) / 10;
				  l1cur = l1cur->next;
				  l2cur = l2cur->next;
			  }
			  else if (!l1cur)
			  {
				  temp->val = (l2cur->val + carry) % 10;
				  carry = (l2cur->val + carry) / 10;
				  l2cur = l2cur->next;
			  }
			  else
			  {
				  temp->val = (l1cur->val + carry) % 10;
				  carry = (l1cur->val + carry) / 10;
				  l1cur = l1cur->next;
			  }
			  if (result == nullptr)
			  {
				  result = temp;
			  }
			  else
			  {
				  resultCur->next = temp;
			  }
			  resultCur = temp;
		  }
		  return result;
	  }
  };
 


int main()
{
	int n;
	ListNode* temp;
	ListNode* head = NULL;
	ListNode* cur;
	cur = head;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		temp = (ListNode*)malloc(sizeof(ListNode));
		cin >> temp->val;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			cur->next = temp;
		}
		cur = temp;
	}


	int n1;
	ListNode* temp1;
	ListNode* head1 = NULL;
	ListNode* cur1;
	cur1 = head1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		temp1 = (ListNode*)malloc(sizeof(ListNode));
		cin >> temp1->val;
		temp1->next = NULL;

		if (head1 == NULL)
		{
			head1 = temp1;
		}
		else
		{
			cur->next = temp1;
		}
		cur1 = temp1;
	}

	Solution sol;
	ListNode *res = sol.addTwoNumbers(head, head1);

	cur = res;
	while (cur)
	{
		cout << cur->val << endl;
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
