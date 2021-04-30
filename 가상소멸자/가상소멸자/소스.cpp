#include <iostream>

using namespace std;

//생성자와 소멸자는 부모
class Parent
{
public :
	Parent()
	{
		cout << "부모 생성자 " << endl;
	}
	virtual ~Parent()
	{
		cout << " 부모 소멸자 " << endl;
	}
	virtual void Print()
	{
		cout << " 부모의 프린트 " << endl;
	}
};
class Child : public Parent
{
public :
	Child()
	{
		cout << "자식 생성자 " << endl;
	}
	virtual ~Child()
	{
		cout << " 자식 소멸자 " << endl;
	}
	virtual void Print()
	{
		cout << " 자식의 프린트" << endl;
	}
};
int main()
{
	Parent* p = new Child();
	
	p->Print();
}