#include <iostream>

using namespace std;

//�����ڿ� �Ҹ��ڴ� �θ�
class Parent
{
public :
	Parent()
	{
		cout << "�θ� ������ " << endl;
	}
	virtual ~Parent()
	{
		cout << " �θ� �Ҹ��� " << endl;
	}
	virtual void Print()
	{
		cout << " �θ��� ����Ʈ " << endl;
	}
};
class Child : public Parent
{
public :
	Child()
	{
		cout << "�ڽ� ������ " << endl;
	}
	virtual ~Child()
	{
		cout << " �ڽ� �Ҹ��� " << endl;
	}
	virtual void Print()
	{
		cout << " �ڽ��� ����Ʈ" << endl;
	}
};
int main()
{
	Parent* p = new Child();
	
	p->Print();
}