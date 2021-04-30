#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
	int winnum_player = 0, winnum_computer =0;
	int player1, player2, case_ =3;
	string str[3] = { "가위","바위","보" };
	while (1)
	{
		
		system("cls");
		while (1)
		{
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
			case 1: cout << "나     : " << str[player1] << endl << "상대방 : " << str[player2] << endl << "컴퓨터 승리" << endl << endl; winnum_computer++; break;
			case 2: cout << "나     : " << str[player1] << endl << "상대방 : " << str[player2] << endl << "나의 승리" << endl << endl; winnum_player++; break;
			default: cout << "0 1 2중에 입력하세요딴거쓰지말고" << endl << endl;
			}
			cout << "나의 승리 횟수 : " << winnum_player << "컴퓨터 승리 횟수 : " << winnum_computer << endl;

			if (winnum_computer == 3 || winnum_player == 3)
			{
				if (winnum_computer == 3)
					cout << "컴퓨터의 최종승리입니다\n";
				else
					cout << "나의 최종승리입니다.\n";
				winnum_computer = 0;
				winnum_player = 0;
				Sleep(3000);
				break;
			}
		}
		
	}

}
