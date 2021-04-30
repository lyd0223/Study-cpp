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
			cout << "더 큽니다\n";
		}
		else if (player_n > answer_n)
		{
			cout << "더 작습니다\n";
		}
		else
		{
			cout << "정답입니다!! \n";
			break;
		}
	}

	
}