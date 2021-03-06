// 138. Copy List with Random Pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;

 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode*, RandomListNode*> origToNew;
		RandomListNode* newListHead = nullptr;
		RandomListNode* newListNodeCur = nullptr;
		RandomListNode* cur = head;
		RandomListNode* temp;
		while (cur)  //复制链表并且建立映射关系
		{
			temp = new RandomListNode(cur->label);
			if (newListHead == nullptr)
			{
				newListHead = temp;
			}
			else
			{
				newListNodeCur->next = temp;
			}
			newListNodeCur = temp;
			origToNew.insert({ cur, newListNodeCur });
			cur = cur->next;
		}
		cur = head;
		newListNodeCur = newListHead;

		while (cur)
		{
			//取对应结点
			newListNodeCur = origToNew[cur];
			newListNodeCur->random = origToNew[cur->random];
			cur = cur->next;
		}
		return newListHead;
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
