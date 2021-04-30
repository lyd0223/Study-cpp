#include <iostream>

using namespace std;

int main()
{
	int guguData[8][9];
	int x, y;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			guguData[i][j] = (i + 2) * (j + 1);
		}
	}
	cout << "몇 단을 볼까요? ";
	cin >> x;
	cout << "몇을 곱할까요? ";
	cin >> y;	
	cout << guguData[x - 2][y - 1];
}