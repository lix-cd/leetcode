// 129. Sum Root to Leaf Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 class Solution {
 public:
	 vector<int> nums;

	 void dfs(TreeNode *node, int curNum)
	 {
		 curNum = curNum * 10 + node->val;
		 if (node->left == nullptr && node->right == nullptr)
		 {
			 cout << curNum << endl;
			 nums.push_back(curNum);
		 }
		 if (node->left)
		 {
			 dfs(node->left, curNum);
		 }
		 if (node->right)
		 {
			 dfs(node->right, curNum);
		 }
	 }
	 int sumNumbers(TreeNode* root) {
		 if (root == nullptr)
		 {
			 return 0;
		 }
		 dfs(root, 0);
		 int sum = 0;
		 auto iter = nums.begin();
		 while (iter != nums.end())
		 {
			 sum += *iter;
			 iter++;
		 }
		 return sum;
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
