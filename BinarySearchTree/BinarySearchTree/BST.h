#pragma once
#include "Node.h"
#include <string>

/*
 Binary Search Tree : 이진트리
 실제 Map은 레드블랙바이너리트리로되어있음.

 */

class BST
{
	Node* mRoot;
public:
	BST()
		:mRoot(nullptr) {}
	~BST() { if (mRoot) delete mRoot; };

	void Insert(int key, std::string value);
	void Remove(int key);
	bool TryGetValue(int key, std::string* pOutput);
	void Print();
};

