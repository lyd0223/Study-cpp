#pragma once
#include "string"

class Node
{
	int mKey;
	std::string mValue; 
	Node* mLeftNode;
	Node* mRightNode;

public:
	Node(int key, std::string value)
		:mKey(key), mValue(value){}

	void Insert(int key, std::string value); 
	bool TryGetValue(int key, std::string* pOutput);

	std::string GetValue() { return mValue; };
	Node* GetLeftNode() { return mLeftNode; };
	Node* GetRightNode() { return mRightNode; };
	/*
	Node* Remove(int key, Node** ppThis);
	Node* GetMinNode(int key, std::string* pOutput);
	*/
};

