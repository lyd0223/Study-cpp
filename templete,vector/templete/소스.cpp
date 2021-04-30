#include <iostream>
#include <string>
#include <vector>
using namespace std;

//템플릿 
//클래스 또는 함수에만 달아줘야함.

//STL : Standar Template Library
// 자료구조 : 데이터 관리를 편하게 하기위해사용하는놈.


template <class t1, class t2>
void add(t1 t, t2 tt)
{
	cout << t + tt << endl;
}

template<typename t>
class Value
{
public:
	t mValue;
};


int main()
{

	add<int,int>(1, 2);
	add<float,float>(1.111, 2.222);
	add<string,string>("a", "b");
	
	Value<int> value;
	value.mValue = 3;

	//vector : 가변적인 길이를 가짐!
	vector<int> vInt;
	vInt.push_back(10);
	vInt.push_back(20);
	vInt.push_back(30);
	vInt.push_back(40);
	vInt.push_back(50);
	vInt.push_back(60);
	vInt.push_back(70);
	vInt.pop_back();
	cout << "--------------------------------------" << endl;;
	cout << vInt.size() << endl << endl;
	
	//반복자 iterator
	vector<int>::iterator iter = vInt.begin();
	
	for (; iter != vInt.end(); ++iter)
	{
		//*반복자변수 : 반복자가 가리키는 데이터접근
		cout << *iter << endl;
	}
	vInt.erase(vInt.begin() + 1);
	vInt.insert(vInt.begin()+4, 1000);
	cout << "--------------------------------------" << endl;;
	for (iter = vInt.begin(); iter != vInt.end(); ++iter)
	{
		//*반복자변수 : 반복자가 가리키는 데이터접근
		//포인터랑 다름.
		cout << *iter << endl;
	}
	iter = vInt.end()-1;
	cout << *(vInt.end() - 1) << endl;
	
}