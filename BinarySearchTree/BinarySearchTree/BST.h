#pragma once
#include "Node.h"
#include <string>

/*
 Binary Search Tree : ����Ʈ��
 ���� Map�� ��������̳ʸ�Ʈ���εǾ�����.

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

