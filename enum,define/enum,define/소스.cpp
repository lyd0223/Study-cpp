#include <iostream>

using namespace std;

#define BingoCount 10
#define macro cout << "macro~~~" <<endl;
#define OUTPUT(str) cout << str << endl

enum RockSisersPaper
{
	SISERS =0,
	ROCK,
	PAPER = 100
};

int main()
{
	//��ó���� define : �ڵ��� ������/���뼺 ������ ���� ���
	//�ڵ嵵 ��� ����. \�� ����ؼ� ���������ټ�����. �����ٻ�밡��.
	//�Լ�ó�� ���ڸ� �־��ټ�������.
	int bingoSheet[BingoCount][BingoCount];

	macro
	OUTPUT("ddddd");

	//������ enum : ������ �̸��� ���� �� ����. ������ ����.
	RockSisersPaper rsp;
	cout << SISERS << endl;
	
}