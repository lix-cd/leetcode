// 133. Clone Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

 class Solution {
 public:
	 UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		 if (!node)
			 return nullptr;
		 queue<UndirectedGraphNode*>	q;
		 UndirectedGraphNode *cur;
		 UndirectedGraphNode *newCur;
		 UndirectedGraphNode *newGraph = new UndirectedGraphNode(node->label);
		 hash[node] = newGraph;
		 q.push(node);
		 while (!q.empty())
		 {
			 cur = q.front();
			 q.pop();
			 vector<UndirectedGraphNode*> curNeibors = cur->neighbors;
			 auto iter = curNeibors.begin();
			 while (iter != curNeibors.end())
			 {
				 if (hash.find(*iter) == hash.end()) //未创建
				 {
					 hash[*iter] = new UndirectedGraphNode((*iter)->label);
					 q.push(*iter);
				 }
				 hash[cur]->neighbors.push_back(hash[*iter]);
				 iter++;
			 }
		 }
		 return newGraph;
	 }
 private:
	 unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
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
