

#include <iostream>
#include <vector>
#include <thread>
#include <Windows.h>



//thread_local 테스트용 프로젝트


std::vector<std::thread> gThreadList;
thread_local int gThreadLocalValue;

void Func()
{
	while (true)
	{
		std::cout << "Thread" << gThreadLocalValue++ << std::endl;
		Sleep(1000);
	}
}
int main()
{
	
	for (int i = 0; i < 10; i++)
	{
		gThreadList.push_back(std::thread(Func));
	}
	

	int* Test = new int;
	char* TestChar = reinterpret_cast<char*>(Test);
	
	std::cout << Test << std::endl;
	std::cout << TestChar << std::endl;
	

	Sleep(INFINITE);


}
