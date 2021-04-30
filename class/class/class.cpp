#include <iostream>
#include <string>

using namespace std;

//클래스 vs구조체
//클래스는 기본 접근지정자가 private
//구조체는					 public

//구조체 : 변수만 넣어놓는 데이터 덩어리를 만들때 사용
//클래스 : 변수와 함수를 조합한 객체를 만들때 사용

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