#pragma once
#include <iostream>
#include <vector>
using namespace std;
// 참고자료 https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=jidon333&logNo=60211997658
template<class T,unsigned int BlOCK_SIZE = 100>
class MemoryPool
{
private:
	static unsigned char* mPoolPointer;
	static vector<unsigned char*> mPointerForRelease;
	
	
public :
	static void AllocBlock(unsigned int blockSize = BlOCK_SIZE)
	{
		//100(blocksize)짜리 크기의 포인터를만듬.
		mPoolPointer = new unsigned char[sizeof(T) * blockSize];
		mPointerForRelease.push_back(mPoolPointer);
		
		//이부분 잘 이해안감
		unsigned char** current = reinterpret_cast<unsigned char**>(mPoolPointer);
		unsigned char* next = mPoolPointer;

		for (int i = 0; i < blockSize; i++)
		{
			next += sizeof(T);
			*current = next;
			current = reinterpret_cast<unsigned char**>(next);
		}
		*current = nullptr;
	}
	static void* operator new(unsigned int allocSize)
	{
		if (!mPoolPointer)
		{
			AllocBlock();
		}
		unsigned char* returnPointer = mPoolPointer;
		mPoolPointer = *reinterpret_cast<unsigned char**>(returnPointer);
		return returnPointer;
	}
	static void operator delete(void* deletePointer)
	{
		
		*reinterpret_cast<unsigned char**>(deletePointer) = mPoolPointer;
		mPoolPointer = static_cast<unsigned char*>(deletePointer);
		
	}
	static void Release()
	{
		for (auto i = mPointerForRelease.begin(); i != mPointerForRelease.end(); i++)
		{
			delete[] * i;
		}
	}
};

//클래스안의 스태틱변수는 클래스 밖에서 초기화를 해줘야함.
template<class T, unsigned int BlOCK_SIZE>
unsigned char* MemoryPool<T, BlOCK_SIZE>::mPoolPointer = nullptr;

template<class T, unsigned int BlOCK_SIZE>
vector<unsigned char*> MemoryPool<T, BlOCK_SIZE>::mPointerForRelease;
