// operator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0;
	// 대입연산자 = 
	// 연산자 + - * / %
	a = 11;
	b = 13;
	cout << a + b << endl;
	 
	// 복합대입연산자 += -= *= /= %= 
	a += b;
	cout << a << endl;

	// 증감연산자 -- ++
	cout << a++ << endl;  //후치 코드실행 후 증감
	cout << ++a << endl;  //전치 코드실행 전 증감

	// 관계연산자 == != > < >= <= 
	// 관계비교해서 true or false값 뱉음. 
	// true == 1 (0을제외한숫자는 컴퓨터는 참으로인식)
	// false == 0
	bool bol;
	cout << a << endl << b << endl;
	bol = a < b;
	cout << bol << endl;
	bol = a != b;
	cout << bol << endl;

	//실습
	
	while (1)
	{
		int age = 0;
		cout << "나이입력 : ";
		cin >> age;

		bool res = 0;

		res = age >= 19;
		cout << "성인인가요? " <<res << endl;

		res = age == 20;
		cout << "주민등록증 발급대상인가요? " << res << endl;


		res = (age % 10) == 9;
		cout << "아홉수인가요? " << res << endl;
		
	}

	return 0;
	
}