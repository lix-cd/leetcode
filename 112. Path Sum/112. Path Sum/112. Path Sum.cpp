// 112. Path Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	  int sum;
	  bool has = false;
	  void dfs(TreeNode* node, int curSum)
	  {
		  curSum += node->val;
		  if (!node->left && !node->right&&curSum == sum)
		  {
			  has = true;
			  return;
		  }
		  if (node->left)
			  dfs(node->left, curSum);
		  if (node->right)
			  dfs(node->right, curSum);
	  }
	  bool hasPathSum(TreeNode* root, int sum) {
		  if (!root)
			  return false;
		  this->sum = sum;
		  dfs(root, 0);
		  return this->has;
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
