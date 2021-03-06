// 146. LRU Cache.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;
class LRUCache {
public:

	LRUCache(int capacity) {
		cap = capacity;
		curDataCount = 0;
		hash = unordered_map<int, list<pair<int, int>>::iterator>();
		l = list<pair<int, int>>();
	}

	int get(int key) {
		auto iter = hash.find(key);
		if (iter != hash.end())
		{
			int ret = iter->second->second;
			l.splice(l.begin(), l, iter->second);
			return ret;
		}
		else return -1;
	}

	void put(int key, int value) {
		if (get(key)!=-1) //存在
		{
			auto iter = hash.find(key);
			iter->second->second = value;
			l.splice(l.begin(), l, iter->second);
		}
		else
		{
			if (curDataCount < cap) //未放满
			{
				auto p = make_pair(key, value);
				l.push_front(p);
				hash[key] = l.begin();
				curDataCount++;
			}
			else
			{
				auto p = make_pair(key, value);
				l.push_front(p);
				hash[key] = l.begin();
				int lastKey = l.back().first;
				hash.erase(lastKey);
				l.pop_back();
			}
		}
		
	}
private:
	int cap;
	int curDataCount;
	unordered_map<int, list<pair<int, int>>::iterator> hash;
	list<pair<int, int>> l;
};

int main()
{
	LRUCache *cache = new LRUCache(1);

	cache->put(2, 1);
	cout<<cache->get(2)<<endl;       // returns 1

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
