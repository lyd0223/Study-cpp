#include <iostream>

using namespace std;

#define BingoCount 10
#define macro cout << "macro~~~" <<endl;
#define OUTPUT(str) cout << str << endl

enum RockSisersPaper
{
	SISERS =0,
	ROCK,
	PAPER = 100
};

int main()
{
	//전처리기 define : 코드의 가독성/재사용성 증가를 위해 사용
	//코드도 사용 가능. \를 사용해서 구분지어줄수있음. 여러줄사용가능.
	//함수처럼 인자를 넣어줄수도있음.
	int bingoSheet[BingoCount][BingoCount];

	macro
	OUTPUT("ddddd");

	//열거형 enum : 정수에 이름을 붙일 수 있음. 가독성 증가.
	RockSisersPaper rsp;
	cout << SISERS << endl;
	
}