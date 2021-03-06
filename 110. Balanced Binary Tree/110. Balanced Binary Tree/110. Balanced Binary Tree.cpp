// 110. Balanced Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	int getDepth(TreeNode *root)
	{
		if (!root)
			return 0;
		return getDepth(root->left) > getDepth(root->right) ? getDepth(root->left) +1: getDepth(root->right)+1;
	}
	bool isBalanced(TreeNode* root) {
		int differ = getDepth(root->left) - getDepth(root->right);
		if (differ < -1 || differ>1)
			return true;
		else
			return false;
		if (isBalanced(root->left) && isBalanced(root->right))
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
