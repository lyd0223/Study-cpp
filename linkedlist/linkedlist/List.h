#pragma once
#include <iostream>
using namespace std;

template <typename T>

class List final
{
	class Node
	{
	public:
		T mData;
		Node* mNextNode;
		Node* mPrevNode;

		Node()
		{
			mNextNode = nullptr;
			mPrevNode = nullptr;
		}
		~Node()
		{
			if (mNextNode)
			{
				delete mNextNode;
			}
		}
	};
	
public:
	class Iterator final
	{
	private:
		friend class List;
		Node* mCurrentNode;

	public:
		Iterator() : mCurrentNode(nullptr) {}
		
		Iterator& operator++() //밖에서도 수정할수있게 &붙임
		{
			mCurrentNode = mCurrentNode->mNextNode;
			return *this;
		}
		Iterator& operator--()
		{
			mCurrentNode = mCurrentNode->mPrevNode;
			return *this;
		}
		T& operator*()
		{
			return mCurrentNode->mData;
		}
		bool operator==(const Iterator& iter)
		{
			return mCurrentNode == iter.mCurrentNode;
		}
		bool operator!=(const Iterator& iter)
		{
			return mCurrentNode != iter.mCurrentNode;
		}
	};

private :
	Node* mRoot;
public:
	List() : mRoot(nullptr) {}
	~List() { if (mRoot) delete mRoot; }
	
	void Push_Back(T data)
	{
		Node* newNode = new Node();
		newNode->mData = data;

		if (mRoot == nullptr)
		{
			mRoot = newNode;
		}
		else
		{
			Node* temp  = mRoot;
			while (temp->mNextNode != nullptr)
			{
				temp = temp->mNextNode;
			}
			temp->mNextNode = newNode;
			newNode->mPrevNode = temp;
		}
	}
	void Print()
	{
		Node* temp = new Node();
		temp = mRoot;
		
		while (temp != nullptr)
		{
			cout << temp->mData <<endl;
			temp = temp->mNextNode;
		}
	}
	Iterator Begin()
	{
		Iterator iter;
		iter.mCurrentNode = mRoot;
		return iter;
	}
	Iterator End()
	{
		Iterator iter;
		iter.mCurrentNode = nullptr;
		return iter;
	}
	void Erase(const Iterator& iter)   //입력받은 iter로 삭제
	{
		if (iter.mCurrentNode == mRoot)
		{
			Node* nexttemp = iter.mCurrentNode->mNextNode;
			
			mRoot = nexttemp;
			mRoot->mPrevNode = nullptr;
		}
		else if (iter.mCurrentNode->mNextNode == nullptr)
		{
			Node* prevtemp = iter.mCurrentNode->mPrevNode;
			delete(prevtemp->mNextNode);
			prevtemp->mNextNode = nullptr;
		}
		else
		{
			Node* prevtemp = iter.mCurrentNode->mPrevNode;
			Node* nexttemp = iter.mCurrentNode->mNextNode;

			prevtemp->mNextNode = nexttemp;
			nexttemp->mPrevNode = prevtemp;
		}
	}

	void Erase(const T& data)   //데이터가 일치하는 iter삭제
	{
		Node* temp = mRoot;
		while (temp->mData != data)
		{
			temp = temp->mNextNode;
		}

		if (temp == mRoot)
		{
			Node* nexttemp = temp->mNextNode;

			mRoot = nexttemp;
			mRoot->mPrevNode = nullptr;
		}
		else if (temp->mNextNode == nullptr)
		{
			Node* prevtemp = temp->mPrevNode;
			delete(prevtemp->mNextNode);
			prevtemp->mNextNode = nullptr;
		}
		else
		{
			Node* prevtemp = temp->mPrevNode;
			Node* nexttemp = temp->mNextNode;

			prevtemp->mNextNode = nexttemp;
			nexttemp->mPrevNode = prevtemp;
		}
		
	} 
};

