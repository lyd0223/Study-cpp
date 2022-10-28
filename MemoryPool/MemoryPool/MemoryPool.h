#pragma once
#include <iostream>
#include <vector>
using namespace std;
// 참고자료 https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=jidon333&logNo=60211997658
/*
메모리 해제와 할당(new,delete)는 시스템콜이 발생한다.
시스템콜은 꽤나 많은 시간을 소모하기 때문에, 이를 줄이기 위해
공간을 먼저 할당 해 둔 뒤, 메모리 생성 또는 해제가 필요할 시 그 공간을 사용하는 방식을 메모리 풀이라고한다.

메모리풀은 먼저 (원하는 사이즈의 블록 개수 * 객체 크기)만큼을 생성해두고,
블록의 첫번째에는 다음 블록 주소를 담고, 그 뒤로는 객체를 담는다.

*/
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
	static void* operator new(size_t allocSize)
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
