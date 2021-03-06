// 199. Binary Tree Right Side View.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
  class Solution {
  public:
	  vector<int> result;
	  void bfs(TreeNode* node)
	  {
		  queue<TreeNode*> q;
		  TreeNode* curNode;
		  q.push(node);
		  while (!q.empty())
		  {
			  int size = q.size();
			  while (size--)
			  {
				  curNode = q.front();
				  q.pop();
				  if (size == 0)
				  {
					  result.push_back(curNode->val);
				  }
				  if (curNode->left)
					  q.push(curNode->left);
				  if (curNode->right)
					  q.push(curNode->right);
			  }
		  }
	  }
	  vector<int> rightSideView(TreeNode* root) {
		  if (!root)
			  return vector<int>();
		  this->result = vector<int>();
		  bfs(root);
		  return result;
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
