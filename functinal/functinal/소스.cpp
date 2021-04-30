#include <iostream>
#include <functional>

using namespace std;


// �Լ������� : 
// �Լ��� �Լ��� �ּҸ� �����Ѵ�.

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
	cout << "�׳�Print()" << endl;
}
class Test
{
public :
	void Print()
	{
		cout << "TestŬ������ Print()" << endl;
	}
};
int main()
{
	function<void()> t1;
	//bind���Ἥ �������.
	t1 = bind(&Print);
	t1();
	//�̰ŵ� �����ѵ�, �Ű������� �������� �����ع���.
	//t1 = Print;

	//Ŭ�������� �Լ� ���.
	Test* test = new Test();

	function<void()> t2 = bind(&Test::Print, test);

	t2();
	int a = 5;
	int b = 3;
	
	//�Ű������� �ִ� �Լ� ���.
	function<int(int,int)> t = bind(&sum,placeholders::_1,placeholders::_2);
	
	int c;

	c = t(a,b);

	cout << c << endl;

	//���ٽ� : �����Լ�
	//[ĸ��](�Ű�����){�Լ����౸��}
	//ĸ�İ�����ã�ƺ���.
	function<void()> func = []() {cout << "�̰��� ����. �����Դϴ�" << endl; };
	func();
	function<void(string)> func2 = [](string str) {cout << str << endl; };
	func2("�Ͷ���?");
	
}