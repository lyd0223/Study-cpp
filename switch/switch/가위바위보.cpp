#include <iostream>
using namespace std;
#include <string>

int main()
{
	//논리연산자 
	//A && B : AND연산자 (앤퍼슨 또는 레퍼런스) 
	//A || B : 
	//switch : 제어문중하나

	int player1,player2,case_;
	string str[3] = { "가위","바위","보" };
	while(1)
	{
		case_ = 3;
		cin >> player1;
		srand(time(NULL));
		
		player2 = rand() % 3;

		if (player1 == player2)
			case_ = 0;
		else if ((player1 == 0 && player2 == 1) || (player1 == 1 && player2 == 2) || (player1 == 2 && player2 == 0))
			case_ = 1;
		else if ((player1 == 0 && player2 == 2) || (player1 == 1 && player2 == 0) || (player1 == 2 && player2 == 1))
			case_ = 2;
			
		switch (case_)
		{ 
		case 0: cout << "나     : " << str[player1] << endl << "상대방 : " << str[player2] << endl << "비김" << endl << endl; break;
		case 1: cout << "나     : " << str[player1] << endl << "상대방 : " << str[player2] << endl << "컴퓨터 승리" << endl << endl; break;
		case 2: cout << "나     : " << str[player1] << endl << "상대방 : " << str[player2] << endl << "나의 승리" << endl << endl; break;
		default: cout << "0 1 2중에 입력하세요딴거쓰지말고" << endl << endl;
		}
	}
	
}