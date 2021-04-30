#include <string>
#include <iostream>
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	int num[3], player_num[3] ,n;
	int strike = 0, ball = 0;

	for (int i = 0; i < 3; i++)
	{
		num[i] = rand() % 10;
	}
	
	while (1) //중복확인
	{
		if (num[0] == 0)
			num[0] = rand() % 10;
		if (num[0] == num[1])
			num[1] = rand() % 10;
		else if (num[1] == num[2])
			num[2] = rand() % 10;
		else if (num[2] == num[0])
			num[0] = rand() % 10;
		else 
			break;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << num[i];
	}
	cout << endl;

	while (1) 
	{
		cin >> n;
		
		player_num[0] = n / 100;
		n %= 100;
		player_num[1] = n / 10;
		n %= 10;
		player_num[2] = n;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j && player_num[i] == num[j])
				{
					strike++;
				}
				if (i != j && player_num[i] == num[j])
				{
					ball++;
				}
				
			}
		}
		if (strike == 0 && ball == 0)
			cout << "OUT" << endl;
		else
			cout << strike << " STRIKE " << ball << " BALL" << endl;
		if (strike == 3)
		{
			cout << "맞췄습니다!!";
			break;
		}
		strike = 0;
		ball = 0;
	}


}