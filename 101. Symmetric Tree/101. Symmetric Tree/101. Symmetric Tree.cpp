// 101. Symmetric Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		isMirror(root, root);
	}
	bool isMirror(TreeNode *t1, TreeNode *t2)
	{
		if (t1 == NULL && t2 == NULL)
			return true;
		else if (t1 == NULL || t2 == NULL)
			return false;
		if (t1->val == t2->val&&isMirror(t1->left, t2->right)
			&& isMirror(t1->right, t2->left))
			return true;
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
