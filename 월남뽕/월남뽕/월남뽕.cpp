#include<iostream>
#include<string>
#include<ctime>
#include<Windows.h>


using namespace std;


class Card
{
public:
	string pattern;
	int num;

	void printCard()
	{
		if (num == 11 || num == 12 || num == 13)
		{
			if (num == 11)
				cout << pattern << "J" ;
			if (num == 12)
				cout << pattern << "Q" ;
			if (num == 13)
				cout << pattern << "K";
		}
		else
			cout <<pattern << num;
	}
	
};
void thisturnCard(string str, Card* card ,int i)
{
	
	if (card[i].num == 11 || card[i].num == 12 || card[i].num == 13)
	{
		if (card[i].num == 11)
			cout << str << " : J" << card[i].pattern << endl;
		if (card[i].num == 12)
			cout << str << " : Q" << card[i].pattern << endl;
		if (card[i].num == 13)
			cout << str << " : K" << card[i].pattern << endl;
	}
	else
		cout << str << " : " << card[i].num << card[i].pattern << endl;
}
int main()
{
	srand(time(NULL));
	Card card[52];
	int remain[13];
	int betMoney, myMoney = 777;
	int x = 0;
	
	//����
	int ranA, ranB;
	Card temp;

	while (1)
	{
		
		x = 0;
		for (int i = 0; i < 52; i++)
		{
			if (i % 4 == 0)
			{
				x++;
			}
			card[i].num = x;
			if (i %4 == 0)
				card[i].pattern = "��";
			else if(i%4 == 1) card[i].pattern = "��";
			else if(i%4 ==2) card[i].pattern = "��";
			else if(i%4 == 3) card[i].pattern = "��";

		}
		for (int i = 0; i < 100; i++)
		{
			ranA = rand() % 52;
			ranB = rand() % 52;

			temp = card[ranA];
			card[ranA] = card[ranB];
			card[ranB] = temp;
		}
		for(int i =0; i<13; i++)
			remain[i] = 4;
		/*
		for (int i = 0; i < 52; i++)
		{
			cout << card[i] << " ";
			if (i % 5 == 0)
				cout << endl;
		}*/

		for (int i = 0; i < 52; i +=3)
		{
			cout << "���� �������� " << myMoney << "$�Դϴ�" << endl << endl;
			if (i > 49)
			{
				cout << endl << "ī�带 �����մϴ�." << endl << endl;
				Sleep(2000);
				break;
			}
			Sleep(1000);
			cout << "ù��° ī��� ";
			card[i].printCard();
			cout << endl;
			remain[card[i].num -1] -= 1;

			Sleep(1000);
			cout << "�ι�° ī��� ";
			card[i+1].printCard();
			cout << endl;
			remain[card[i + 1].num -1] -= 1;

			cout << "�󸶸� �����Ͻðڽ��ϱ�? : ";
			while (1)
			{
				cin >> betMoney;
				if (betMoney == 0)
				{
					cout << "ī�� ���ĺ���! : \n";
					for (int j = 0; j < 52; j++)
					{
						if (card[j].num != 0)
						{
							card[j].printCard();

						}
						else cout << "   ";
						if ((j+1) % 3 == 0)
							cout << "\t";
						if ((j+1) % 9 == 0)
							cout << "\n";

					}
					cout << endl;
					break;
				}
				else
				{
					if (betMoney > myMoney)
					{
						cout << "���� �����մϴ�." << endl;
						if (betMoney > myMoney)
						{
							cout << "�󸶸� �����Ͻðڽ��ϱ�? : ";
							continue;
						}
					}
					else
					{
						myMoney -= betMoney;
						break;
					}
				}
			}
			Sleep(2000);
			cout << "����° ī��� ";
			card[i+2].printCard();
			cout << endl;
			remain[card[i + 2].num -1] -= 1;
			
			
			if (card[i].num > card[i + 2].num && card[i + 1].num < card[i + 2].num || card[i +1].num > card[i + 2].num && card[i].num < card[i + 2].num)
			{
				myMoney += betMoney * 2;
				cout << "�÷��̾� Win." << endl;
			}
			else
			{
				cout << "���� Win." << endl;
			}
			if (myMoney == 0)
			{
				break;
			}
			card[i].num = 0;
			card[i + 1].num = 0;
			card[i + 2].num = 0;
			Sleep(2000);
		}
		if (myMoney == 0)
		{
			Sleep(1000);
			cout << "���� ��� �Ұ� �Ѱܳ����ϴ�." << endl;
			break;
		}
	}

}