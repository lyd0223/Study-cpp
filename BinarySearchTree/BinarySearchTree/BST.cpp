#include "BST.h"

#include <iostream>

using namespace std;



void BST::Insert(int key, std::string value)
{
	Node* newNode = new Node(key, value);
	if (mRoot == nullptr)
	{
		mRoot = newNode;
	}
	else
	{
		mRoot->Insert(key, value);
	}
}

void BST::Remove(int key)
{
}

bool BST::TryGetValue(int key, std::string* pOutput)
{
	if (mRoot == nullptr)
		return false;
	else
		return mRoot->TryGetValue(key, pOutput);
}

void BST::Print()
{
	Node* currentNode = mRoot;
	while (currentNode != nullptr)
	{
		cout << currentNode->GetValue() << endl;
		currentNode = currentNode->GetRightNode();
	}
}