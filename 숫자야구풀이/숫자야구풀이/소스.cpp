#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	int i = 0;
	int comNum1, comNum2, comNum3;
	comNum1 = rand() % 9;
	
	while (1)
	{
		cout << "ù��° " << endl;
		
		if (i == 0)
		{
			cout << "�ι��� " << endl;
			i = 1;
			continue;
			
		}

		cout << "����° " << endl;
	}
}