#include <iostream>
#include <vector>
using namespace std;


/* 
 캐스팅 : 형변환
 명시적 형변환 ? 명시적으로 코드를 쳐서 형변환시키는것. 속도가 상대적 빠름.
 묵시적 형변환 ? 명시적으로 코들르 치지않아도 자동으로 되는것.속도가 상대적 느림. ex float->int 

 1.static_cast : 정적캐스팅 , 명시적으로 지정한 형변환만 가능.
 우리가 하던 형변환이랑 생긴거만다르고 기능은 같다.
 int i = (int)f;
 int i = static_cast<int>(f); 위아래 같음.

 2.const_cast : const를 떼는 캐스팅. 쓸일없다.

 3.dynamic_cast :  상속관계에서 업캐스팅,다운캐스팅쓸때쓴다. 특히다운캐스팅.
				  안정성검사를해줌. 만약 잘못된 다운캐스팅시 널포인터를 담아준다.
				  무조건 한개 이상의 가상함수가 있어야 사용가능.
				  가상함수: 부모의 함수를 불러도 자식의함수 실행. 가상함수를 만들면 컴파일러가 가상함수 테이블이란걸 만듬.
						  어떤 가상함수가 호출되었을때 맞게 실행되어야 하는 오버라이딩된 함수의 주소를 저장하는 테이블.
 
 4.reinterpret_cast : 강제형변환. 어떤것이든 해드립니다. 비트단위로 재해석해서 형변환을 해줌. 어떤거든 강제로형변환.
					  빠름. 안정성쓰래기.
					  
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
	void attack()override { cout << "오크공격!" << endl; }
	void deffence()override { cout << "오크방어!" << endl; }
};
class Troll : public Monster 
{ 
public:
	void attack()override { cout << "트롤공격!" << endl; }
	void deffence()override { cout << "트롤방어!" << endl; }
	void Health() { cout << "헬쓰으쌰으쌰" << endl; }
};


// 
//

int main()
{
	//Monster* monster1 = new Monster();
	//Ork* ork = new Ork();
	//Monster* monster2 = new Monster();
	//Troll* troll = new Troll();

	////부모에 자식을 담는건 쌉가능.
	//monster1 = ork;

	//monster1->attack();

	//monster2 = troll;
	//monster2->attack();

	////자식에 부모를 담음.
	//Troll* troll2 = dynamic_cast<Troll*>(monster2);
	//troll2->Health();

	//Ork* ork2 = dynamic_cast<Ork*>(troll2);

	//if (ork2 == NULL)
	//	cout << "오크가 널이야!";

	Monster monster;

	cout << "monster의 크기 : "  << sizeof(monster) << endl;
	0x00e414e7;

}