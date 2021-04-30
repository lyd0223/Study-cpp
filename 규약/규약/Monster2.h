#pragma once
#include <string>
#include<iostream>
using namespace std;


//h(�������) : ���Ǹ� ����.
//������ �ӵ��� ������ �ϱ�����.

class Monster2
{

	//������ : �ش�Ŭ������ �ν��Ͻ��� �Ҵ��ϸ�(�����Ҷ�) �ڵ����� ȣ��Ǵ��Լ�.
	Monster2() { cout << "������" << endl; };
	//�Ҹ��� : �Ҵ����� �Ǹ� �ڵ����� ȣ��Ǵ� �Լ�.
	~Monster2() { cout << "�Ҹ���" << endl;  };

	//���� ������ private�����Ѵ�. ������ �Ҷ� �Լ��� �̿�.
private:
	string m_Name;
	int m_HP;
	int m_MP;

public:
	void Init(string name, int hp, int mp);
	//{
	//	//������Ͽ��� ���Ǹ�����. ������ cpp����
	//	/*m_Name = name;
	//	m_HP = hp;
	//	m_MP = mp;*/
	//};
	void Print();
	
	//�������Լ��� ���� ������ h���Ͽ�.
	string GetName();
	void SetName(string str)
	{
		m_Name = str;
	}
};

