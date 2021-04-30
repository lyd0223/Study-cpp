#include <iostream>
#include <functional>

using namespace std;


// 함수포인터 : 
// 함수는 함수의 주소를 저장한다.

int sum(int a, int b)
{
	return a + b;
}
//int sum(int a, int b, int c, int d)
//{
//	return a + b + c + d;
//}
void Print()
{
	cout << "그냥Print()" << endl;
}
class Test
{
public :
	void Print()
	{
		cout << "Test클래스의 Print()" << endl;
	}
};
int main()
{
	function<void()> t1;
	//bind를써서 집어넣음.
	t1 = bind(&Print);
	t1();
	//이거도 가능한데, 매개변수가 없을때만 가능해버림.
	//t1 = Print;

	//클래스안의 함수 담기.
	Test* test = new Test();

	function<void()> t2 = bind(&Test::Print, test);

	t2();
	int a = 5;
	int b = 3;
	
	//매개변수가 있는 함수 담기.
	function<int(int,int)> t = bind(&sum,placeholders::_1,placeholders::_2);
	
	int c;

	c = t(a,b);

	cout << c << endl;

	//람다식 : 무명함수
	//[캡쳐](매개변수){함수실행구문}
	//캡쳐가뭔지찾아보자.
	function<void()> func = []() {cout << "이곳은 람다. 람다입니다" << endl; };
	func();
	function<void(string)> func2 = [](string str) {cout << str << endl; };
	func2("넌람다?");
	
}