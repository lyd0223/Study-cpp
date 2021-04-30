
#include <iostream>
using namespace std;


int main()
{
	for (int i = 2; i < 10; i++)
	{
		for (int j = 2; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << "  ";
			if (i * j < 10)
			{
				cout << " ";
			}
			if (j%3 == 1)
			{
				cout << endl;
			}
		}
		cout << "\n-------------------------------------" << endl;
	}
}


//break : 반복문탈출
//continue : 아래 코드 스킵후 while은 조건검사로 바로가고, for는 증감식으로 바로감
//실습 1 : 99단출력
//실습 2 : 3단씩 끊어서.