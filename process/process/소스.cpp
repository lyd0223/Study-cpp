#include <iostream>
#include <functional>
#include <thread>

using namespace std;

/*
프로세스? 실행중인 프로그램.
스레드 ? 하나의 프로세스엔 하나 이상의 스레드가 존재.
		실행하는 흐름.
동기 ? 
비동기 ?  

*/

void Func1()
{
	for (int i = 0; i < 100; i++)
	{
		cout << i << endl;
	}
}
void Func2()
{
	for (int i = 100; i < 200; i++)
	{
		cout << i << endl;
	}
}
int main()
{
	thread* thread1 = new thread(bind(&Func1));
	thread* thread2 = new thread(bind(&Func2));

	thread1->join();
	thread2->join();
	
	delete thread1;
	delete thread2;
	
}