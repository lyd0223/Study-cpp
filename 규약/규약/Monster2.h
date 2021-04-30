#pragma once
#include <string>
#include<iostream>
using namespace std;


//h(헤더파일) : 정의만 내림.
//컴파일 속도를 빠르게 하기위해.

class Monster2
{

	//생성자 : 해당클래스의 인스턴스를 할당하면(생성할때) 자동으로 호출되는함수.
	Monster2() { cout << "생성자" << endl; };
	//소멸자 : 할당해제 되면 자동으로 호출되는 함수.
	~Monster2() { cout << "소멸자" << endl;  };

	//보통 변수는 private으로한다. 접근을 할땐 함수를 이용.
private:
	string m_Name;
	int m_HP;
	int m_MP;

public:
	void Init(string name, int hp, int mp);
	//{
	//	//헤더파일에선 정의만해줌. 구현은 cpp에서
	//	/*m_Name = name;
	//	m_HP = hp;
	//	m_MP = mp;*/
	//};
	void Print();
	
	//접근자함수는 보통 구현을 h파일에.
	string GetName();
	void SetName(string str)
	{
		m_Name = str;
	}
};

