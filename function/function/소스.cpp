#include<iostream>
#include <ctime>
using namespace std;

//함수는 재사용성을 높이기위한 , 코드를 하나의 이름으로 묶어놓은것이다.

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



