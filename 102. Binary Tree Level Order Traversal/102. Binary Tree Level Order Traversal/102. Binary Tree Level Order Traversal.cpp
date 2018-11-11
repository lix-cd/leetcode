// 102. Binary Tree Level Order Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		TreeNode* temp;
		q.push(root);
		vector<int> curRow;
		vector<vector<int>> result;
		while (!q.empty())
		{
			int size = q.size();
			curRow.clear();
			while (size--)
			{
				temp = q.front();
				q.pop();
				if(temp->left)
					q.push(temp->left);
				if (temp->right)
					q.push(temp->right);
				curRow.push_back(temp->val);
			}
			result.push_back(curRow);
		}
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
