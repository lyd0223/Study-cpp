#include<iostream>
#include <ctime>
using namespace std;

//�Լ��� ���뼺�� ���̱����� , �ڵ带 �ϳ��� �̸����� ����������̴�.

int threemultiply(int a , int b ,int c)
{
	return a * b * c;
}

int rand1(int a)
{
	return rand()%(a+1);
}

int rand2(int a, int b)
{
	int temp;
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	return (rand() % (b-a+1)) +a;
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		cout << rand2(5,100) << endl;
	}
}



