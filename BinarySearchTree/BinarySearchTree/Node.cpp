#include "Node.h"

void Node::Insert(int key, std::string value)
{
	//�� Ű������ ������ left , ũ�� right
	if (key < mKey)
	{
		if (mLeftNode != nullptr)
			mLeftNode->Insert(key, value);
		else
			mLeftNode = new Node(key, value);
	}
	else if(key>mKey)
	{
		if (mRightNode != nullptr)
			mRightNode->Insert(key, value);
		else
			mRightNode = new Node(key, value);
	}

}

bool Node::TryGetValue(int key, std::string* pOutput)
{
	if (mKey == key)
	{
		*pOutput = mValue;
		return true;
		
	}
	else if (mKey > key)
	{
		if (mLeftNode == nullptr)
			return false;
		else
			mLeftNode->TryGetValue(key, pOutput);
	}
	else if (mKey < key)
	{
		if (mRightNode == nullptr)
			return false;
		else
			mRightNode->TryGetValue(key, pOutput);
	}
}