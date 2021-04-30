#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	int count = 1, sum = 0;
	cin >> n;

	string* str = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < str[i].length(); j++)
		{
			if (str[i][j] == 'O')
			{
				sum += count;
				count++;
			}
			else
			{
				count = 1;
			}
		}
		cout << sum << endl;
		count = 1;
		sum = 0;
	}
}