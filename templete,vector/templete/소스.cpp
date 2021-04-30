#include <iostream>
#include <string>
#include <vector>
using namespace std;

//���ø� 
//Ŭ���� �Ǵ� �Լ����� �޾������.

//STL : Standar Template Library
// �ڷᱸ�� : ������ ������ ���ϰ� �ϱ����ػ���ϴ³�.


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

	//vector : �������� ���̸� ����!
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
	
	//�ݺ��� iterator
	vector<int>::iterator iter = vInt.begin();
	
	for (; iter != vInt.end(); ++iter)
	{
		//*�ݺ��ں��� : �ݺ��ڰ� ����Ű�� ����������
		cout << *iter << endl;
	}
	vInt.erase(vInt.begin() + 1);
	vInt.insert(vInt.begin()+4, 1000);
	cout << "--------------------------------------" << endl;;
	for (iter = vInt.begin(); iter != vInt.end(); ++iter)
	{
		//*�ݺ��ں��� : �ݺ��ڰ� ����Ű�� ����������
		//�����Ͷ� �ٸ�.
		cout << *iter << endl;
	}
	iter = vInt.end()-1;
	cout << *(vInt.end() - 1) << endl;
	
}