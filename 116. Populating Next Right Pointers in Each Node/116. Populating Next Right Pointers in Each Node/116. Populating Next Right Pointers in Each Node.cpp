// 116. Populating Next Right Pointers in Each Node.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
 
class Solution {
public:

	void dfs(TreeLinkNode *parentNode,TreeLinkNode *curNode,bool isLeft)
	{
		if (isLeft)
			curNode->next = parentNode->right;
		else
		{
			if (parentNode->next != nullptr)
			{
				{
					curNode->next = parentNode->next->left;
				}
			}
		}
		if (curNode->left)
			dfs(curNode, curNode->left, true);
		if (curNode->right)
			dfs(curNode, curNode->right, false);
	}

	void connect(TreeLinkNode *root) {
		root->next = nullptr;
		dfs(root, root->left, true);
		dfs(root, root->right, false);
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
