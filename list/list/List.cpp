#include "List.h"
#include <iostream>
using namespace std;

List::List()
	:mRoot(nullptr) //생성자 멤버이니셜라이저 , 생성자호출될때 멤버변수 생성자도 같이호출.
{}

List::~List()
{
	Node* temp = mRoot;
	Node* tempNext = mRoot->mNext;

	while (temp != nullptr)
	{
		tempNext = temp->mNext;
		delete(temp);
		temp = tempNext;
	}
}

void List::Push_Back(int data)
{
	Node* newNode = new Node();
	newNode->mData = data;
	newNode->mNext = nullptr;
	
	if (mRoot == nullptr)
	{
		mRoot = newNode;
	}
	else
	{
		Node* temp = mRoot;
		while (temp->mNext != nullptr)
		{
			temp = temp->mNext;
		}
		
		temp->mNext = newNode;
	}
}
void List::Print()
{
	Node* temp = mRoot;

	while (temp != nullptr)
	{
		cout << temp->mData << endl;
		temp = temp->mNext;
	}
}


//소멸자 되는지 확인
void List::Delete()
{
	Node* temp = mRoot;
	Node* tempNext = mRoot->mNext;

	while (temp != nullptr)
	{
		tempNext = temp->mNext;
		delete(temp);
		temp = tempNext;
	}
}
