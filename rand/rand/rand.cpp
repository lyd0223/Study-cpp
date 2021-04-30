// rand.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	//rand()
	//srand()

	srand(time(NULL));

	for(int i=0; i<10 ; i++)
		cout << rand() % 10 << endl << endl;
	

	for (int i = 0; i < 10; i++)
		cout << rand() % 100 << endl << endl;
	

	for (int i = 0; i < 10; i++)
		cout << rand() % 7+3 << endl;

	for (int i = 0; i < 10; i++)
		cout << rand() % 95 + 5 << endl;
}


//0에서 9까지 랜덤한 수를 출력하는 코드
//0~99까지의 랜덤한 수 
// 3~9까지의 랜덤한 수 
// 5~99까지의 랜덤한 수

