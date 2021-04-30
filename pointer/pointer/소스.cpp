#include <iostream>

using namespace std;

// 전역변수 :여디서든사용가능
//			 프로그램시작될때 생성, 프로그램 끝날때 삭제.
double b = 3.33; 

int main()
{
	//지역변수 : 함수내에서 선언한변수.
	//			 함수 벗어나면 삭제.
	int a = 3;

	cout << " a변수의 값 : " << a << endl;
	cout << " a변수의 크기 : " << sizeof(a) << endl;
	//& : 래퍼런스, 앤퍼슨이라고도불림. 해당변수의 메모리주소를 반환.
	cout << " a변수의 메모리주소 : " << &a << endl;

	cout << " b변수의 값 : " << b << endl;
	cout << " b변수의 크기 : " << sizeof(b) << endl;
	cout << " b변수의 메모리주소 : " << &b << endl;

	//포인터 : 메모리주소(정수)를 담을수있는 변수.
	//포인터는 스택에 저장된다.
	int* aa = &a; //int형 변수의 메모리값을 담는 aa
	double* bb = &b; //double형 변수의 메모리값을 담는 aa
	//사실은 자료형뒤에붙는게아닌 변수앞에붙는거다. 여러 변수를 선언해줄때
	int* aaaaa, * aaa, * aaaa; //라고 선언해야한다.
	cout << " aa변수의 값 : " << aa << endl;
	cout << " aa변수의 크기 : " << sizeof(aa) << endl;
	cout << " aa변수의 메모리주소 : " << &aa << endl;

	cout << " bb변수의 값 : " << bb << endl;
	cout << " bb변수의 크기 : " << sizeof(bb) << endl;
	cout << " bb변수의 메모리주소 : " << &bb << endl << endl;


	//포인터를 왜쓸까 그럼?? 역참조 때문에!!!
	//포인터가 가리키는 메모리주소에 있는 값에 접근하는것.
	cout << "bb변수가 가리키는 메모리주소에 있는값 : "<< *bb << endl;
	//포인터를 이용해서 변수값 바꾸기
	*aa = 30000;
	cout << "aa변수가 가리키는 메모리주소에 있는 값 : " << *aa << endl;

	//정적할당 : 변수 선언하는것으로 메모리가 생성되는 할당방식, 메모리 자동해제.
	//동적할당 : 내가 원할때 메모리를 생성하고,원할 때 삭제가 가능.
	// new : 동적할당을 위해 필요. 데이터타입을 할당해주고, 메모리 주소를 반환하는 연산자.
	cout << new int << endl; //주소값반환
	aa = new int; // 메모리만 할당해서 주소값을 저장. 이래서 포인터가 필요한거다.
	
	//동적할당
	int* ptr = new int; // ptr에 int형을 a개만큼 저장하는 메모리의 앞 주소를 저장.

	*ptr = 999;
	cout << "요기 : " << ptr << endl;
	delete ptr;
	*ptr = 9999;
	cout << "조기 : " << ptr << endl;  //삭제를해서 안된당.

}