#include <iostream>
//내가 만든 헤더파일은 ""로 불러옴.
#include "Monster2.h"
using namespace std;

class Monster
{
public:
	//클래스 내부의 변수는 m_ 또는 m을 붙여준다(멤버)
	int m_HP;
	int m_MP;
	string m_Name;
};
int main()
{

	//1.변수이름규칙
	// 헝가리안식 표기법 : 변수이름앞에 데이터 타입의 약어를 붙이는것
	int iNum;
	float fNum;
	string strname;
	
	// 카멜표기법 : 여러 단어를 조합해서 변수이름을 만들 때 오는 단어의 첫글자를 대문자로
	string itemName; 
	
	//2.함수이름 규칙
	// 시작글자 대문자

	//3. 클래스, 구조체 이름규칙 
	// 시작글자 대문자

	Monster2 mob;
	mob.Init("Ork", 100, 100);
	mob.Print();


}