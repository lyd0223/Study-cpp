#include <iostream>
//���� ���� ��������� ""�� �ҷ���.
#include "Monster2.h"
using namespace std;

class Monster
{
public:
	//Ŭ���� ������ ������ m_ �Ǵ� m�� �ٿ��ش�(���)
	int m_HP;
	int m_MP;
	string m_Name;
};
int main()
{

	//1.�����̸���Ģ
	// �밡���Ƚ� ǥ��� : �����̸��տ� ������ Ÿ���� �� ���̴°�
	int iNum;
	float fNum;
	string strname;
	
	// ī��ǥ��� : ���� �ܾ �����ؼ� �����̸��� ���� �� ���� �ܾ��� ù���ڸ� �빮�ڷ�
	string itemName; 
	
	//2.�Լ��̸� ��Ģ
	// ���۱��� �빮��

	//3. Ŭ����, ����ü �̸���Ģ 
	// ���۱��� �빮��

	Monster2 mob;
	mob.Init("Ork", 100, 100);
	mob.Print();


}