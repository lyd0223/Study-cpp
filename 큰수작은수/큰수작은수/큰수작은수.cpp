#include <iostream>

using namespace std;

int main()
{
	int answer_n, player_n;
	srand(time(NULL));

	answer_n = rand() % 1000;

	while(1)
	{
		cin >> player_n;

		if (player_n < answer_n)
		{
			cout << "�� Ů�ϴ�\n";
		}
		else if (player_n > answer_n)
		{
			cout << "�� �۽��ϴ�\n";
		}
		else
		{
			cout << "�����Դϴ�!! \n";
			break;
		}
	}

	
}