#include <iostream>
#include <string>

using namespace std;

//Ŭ���� vs����ü
//Ŭ������ �⺻ ���������ڰ� private
//����ü��					 public

//����ü : ������ �־���� ������ ����� ���鶧 ���
//Ŭ���� : ������ �Լ��� ������ ��ü�� ���鶧 ���

struct monsterStruct
{
	string name;
	int hp;
	int mp;

};

class monsterClass
{
public :
	string name;
	int hp;
	int mp;

	void Init(string startName, int startHP, int startMP)
	{

	}
	   
private : 

};

int main()
{
	monsterClass monster2;
	monster2.Init("Orc", 100, 100);
	
	monsterClass monster3;
	monster3.name = "Goblin";
	monster3.hp = 50;
	monster3.mp = 50;
	
}