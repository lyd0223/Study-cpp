#include <iostream>
using namespace std;
#include <string>

int main()
{
	//�������� 
	//A && B : AND������ (���۽� �Ǵ� ���۷���) 
	//A || B : 
	//switch : ������ϳ�

	int player1,player2,case_;
	string str[3] = { "����","����","��" };
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
		case 0: cout << "��     : " << str[player1] << endl << "���� : " << str[player2] << endl << "���" << endl << endl; break;
		case 1: cout << "��     : " << str[player1] << endl << "���� : " << str[player2] << endl << "��ǻ�� �¸�" << endl << endl; break;
		case 2: cout << "��     : " << str[player1] << endl << "���� : " << str[player2] << endl << "���� �¸�" << endl << endl; break;
		default: cout << "0 1 2�߿� �Է��ϼ�����ž�������" << endl << endl;
		}
	}
	
}