#pragma once
class List
{

	struct Node
	{
		int mData;
		Node* mNext;
	};
	
	Node* mRoot;
	
public :
	List();
	~List();
	void Push_Back(int data);
	void Print();
	void Delete();
};

