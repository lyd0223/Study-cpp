#include <iostream>
#include <functional>
#include <thread>

using namespace std;

/*
���μ���? �������� ���α׷�.
������ ? �ϳ��� ���μ����� �ϳ� �̻��� �����尡 ����.
		�����ϴ� �帧.
���� ? 
�񵿱� ?  

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