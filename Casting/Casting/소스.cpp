#include <iostream>
#include <vector>
using namespace std;


/* 
 ĳ���� : ����ȯ
 ����� ����ȯ ? ��������� �ڵ带 �ļ� ����ȯ��Ű�°�. �ӵ��� ����� ����.
 ������ ����ȯ ? ��������� �ڵ鸣 ġ���ʾƵ� �ڵ����� �Ǵ°�.�ӵ��� ����� ����. ex float->int 

 1.static_cast : ����ĳ���� , ��������� ������ ����ȯ�� ����.
 �츮�� �ϴ� ����ȯ�̶� ����Ÿ��ٸ��� ����� ����.
 int i = (int)f;
 int i = static_cast<int>(f); ���Ʒ� ����.

 2.const_cast : const�� ���� ĳ����. ���Ͼ���.

 3.dynamic_cast :  ��Ӱ��迡�� ��ĳ����,�ٿ�ĳ���þ�������. Ư���ٿ�ĳ����.
				  �������˻縦����. ���� �߸��� �ٿ�ĳ���ý� �������͸� ����ش�.
				  ������ �Ѱ� �̻��� �����Լ��� �־�� ��밡��.
				  �����Լ�: �θ��� �Լ��� �ҷ��� �ڽ����Լ� ����. �����Լ��� ����� �����Ϸ��� �����Լ� ���̺��̶��� ����.
						  � �����Լ��� ȣ��Ǿ����� �°� ����Ǿ�� �ϴ� �������̵��� �Լ��� �ּҸ� �����ϴ� ���̺�.
 
 4.reinterpret_cast : ��������ȯ. ����̵� �ص帳�ϴ�. ��Ʈ������ ���ؼ��ؼ� ����ȯ�� ����. ��ŵ� ����������ȯ.
					  ����. ������������.
					  
 */

class Monster 
{
	int a;
	int b;
public : 
	virtual void attack() {};
	virtual void deffence() {};
	virtual void run() {};
};
class Ork :public Monster 
{
	int a;
	int b;

public:
	void attack()override { cout << "��ũ����!" << endl; }
	void deffence()override { cout << "��ũ���!" << endl; }
};
class Troll : public Monster 
{ 
public:
	void attack()override { cout << "Ʈ�Ѱ���!" << endl; }
	void deffence()override { cout << "Ʈ�ѹ��!" << endl; }
	void Health() { cout << "�ﾲ���X���X" << endl; }
};


// 
//

int main()
{
	//Monster* monster1 = new Monster();
	//Ork* ork = new Ork();
	//Monster* monster2 = new Monster();
	//Troll* troll = new Troll();

	////�θ� �ڽ��� ��°� �԰���.
	//monster1 = ork;

	//monster1->attack();

	//monster2 = troll;
	//monster2->attack();

	////�ڽĿ� �θ� ����.
	//Troll* troll2 = dynamic_cast<Troll*>(monster2);
	//troll2->Health();

	//Ork* ork2 = dynamic_cast<Ork*>(troll2);

	//if (ork2 == NULL)
	//	cout << "��ũ�� ���̾�!";

	Monster monster;

	cout << "monster�� ũ�� : "  << sizeof(monster) << endl;
	0x00e414e7;

}