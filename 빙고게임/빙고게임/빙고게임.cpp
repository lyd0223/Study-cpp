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
	
	//�����ǿ� a~z �ֱ�
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = c++;
		}
	}
	//������ ����
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
	//������ ���
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

	//���� ���߱����
	while (1)
	{
		//�Է�
		myc = _getch();
		//�Է��Ѱ������� #���� �������ֱ�
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
		//���κ��� üũ
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
				cout << bingo << "���� �ϼ�" << endl;
			}
			count = 0;
		}
		
		//���κ��� üũ
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
				cout << bingo << "���� �ϼ�" << endl;
			}
			count = 0;
		}
		//�밢������üũ
		for (int i = 0; i < 5; i++)
		{
			if (arr[i][i] == '#')
				count++;
		}
		if (count == 5 && dia_bool[0] == 0)
		{
			bingo++;
			dia_bool[0] = 1;
			cout << bingo << "���� �ϼ�" << endl;
		}
		count = 0;
		if (arr[4][0] == '#' && arr[3][1] == '#' && arr[2][2] == '#' && arr[1][3] == '#' && arr[0][4] == '#' &&dia_bool[1]==0)
		{
			bingo++;
			dia_bool[1] = 1;
			cout << bingo << "���� �ϼ�" << endl;
		}
		//�ײ�
		if (bingo == 3)
		{
			cout << "3����ϼ� �׳�" << endl;
			break;
		}
	}

}