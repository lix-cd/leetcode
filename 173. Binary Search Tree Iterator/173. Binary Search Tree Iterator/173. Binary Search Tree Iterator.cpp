// 173. Binary Search Tree Iterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class BSTIterator {
public:
	stack<TreeNode*> s;
	BSTIterator(TreeNode *root) {
		help(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (s.empty())
			return false;
		else
			return true;
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* node = s.top();
		int result = node->val;
		s.pop();
		help(node->right);
		return result;
	}
	void help(TreeNode *node)
	{
		while (node != nullptr)
		{
			if (node)
				s.push(node);
			node = node->left;
		}
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
