// 145. Binary Tree Postorder Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//Recursive solution
//class Solution {
//public:
//	vector<int> result;
//	void dfs(TreeNode* node)
//	{
//		if (!node)
//			return;
//		dfs(node->left);
//		dfs(node->right);
//		result.push_back(node->val);
//	}
//	vector<int> postorderTraversal(TreeNode* root) {
//		dfs(root);
//		return result;
//	}
//};

 class Solution {
 public:
	 vector<int> postorderTraversal(TreeNode* root) {
		 vector<int> result;
		 stack<TreeNode*> s;
		 TreeNode* curNode;
		 s.push(root);
		 while (!s.empty())
		 {
			 curNode = s.top();
			 s.pop();
			 if (!curNode)
			 {
				 s.push(curNode->right);
				 s.push(curNode->left);
			 }
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
