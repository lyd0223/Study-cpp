#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

int main()
{
	char arr[5][5];
	bool row_bool[5] = { 0, };
	bool col_bool[5] = { 0, };
	bool dia_bool[2] = { 0, };
	int c = 97;
	int tmp;
	char myc;
	int count = 0,bingo = 0;
	srand(time(NULL));
	int ran1,ran2,ran3,ran4;
	
	//빙고판에 a~z 넣기
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = c++;
		}
	}
	//빙고판 셔플
	for (int i = 0; i < 100; i++)
	{
		ran1 = rand() % 5;
		ran2 = rand() % 5;
		ran3 = rand() % 5;
		ran4 = rand() % 5;
		tmp = arr[ran1][ran2];
		arr[ran1][ran2] = arr[ran3][ran4];
		arr[ran3][ran4] = tmp;
	}
	//빙고판 출력
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << arr[i][j] << " ";
			if (arr[i][j] < 10)
				cout << " ";
		}
		cout << endl; 
	}
	cout << endl;

	//빙고 맞추기시작
	while (1)
	{
		//입력
		myc = _getch();
		//입력한게있으면 #으로 변경해주기
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arr[i][j] == myc)
				{
					arr[i][j] = '#';
					cout << arr[i][j] << " ";
				}
				else
				{
					cout << arr[i][j] << " ";
					if (arr[i][j] < 10)
						cout << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
		//가로빙고 체크
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arr[i][j] == '#')
					count++;
			}
			if (count == 5 && row_bool[i] == 0)
			{
				bingo++;
				row_bool[i] = 1;
				cout << bingo << "빙고 완성" << endl;
			}
			count = 0;
		}
		
		//세로빙고 체크
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arr[j][i] == '#')
					count++;
			}
			if (count == 5 && col_bool[i] == 0 )
			{
				bingo++;
				col_bool[i] = 1;
				cout << bingo << "빙고 완성" << endl;
			}
			count = 0;
		}
		//대각선빙고체크
		for (int i = 0; i < 5; i++)
		{
			if (arr[i][i] == '#')
				count++;
		}
		if (count == 5 && dia_bool[0] == 0)
		{
			bingo++;
			dia_bool[0] = 1;
			cout << bingo << "빙고 완성" << endl;
		}
		count = 0;
		if (arr[4][0] == '#' && arr[3][1] == '#' && arr[2][2] == '#' && arr[1][3] == '#' && arr[0][4] == '#' &&dia_bool[1]==0)
		{
			bingo++;
			dia_bool[1] = 1;
			cout << bingo << "빙고 완성" << endl;
		}
		//겜끗
		if (bingo == 3)
		{
			cout << "3빙고완성 겜끝" << endl;
			break;
		}
	}

}