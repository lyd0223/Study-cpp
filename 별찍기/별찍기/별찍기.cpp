#include <iostream>

using namespace std;

int main()
{
	//1번
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 ; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	//2번
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5-i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;


	//3번
	int j = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int k = 1; k <= i - j; k++)
		{
			cout << " ";
		}
		for (j = 6 - i - 1; j >= 1; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	//4번
	for (int i = 0; i < 6; i++)
	{
		for (int k = 1; k <= i - j; k++)
		{
			cout << "*";
		}
		for (j = 6 - i - 1; j >= 1; j--)
		{
			cout << " ";
		}
		cout << endl;
	}
}
