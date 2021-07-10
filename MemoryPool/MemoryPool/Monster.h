#pragma once
#include "MemoryPool.h"
class Monster : public MemoryPool<Monster,50>
{
private :
	int mHP, mMP;
	int* arr[100000];
};

