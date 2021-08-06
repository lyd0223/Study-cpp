#include <iostream>

/*
*	2021.08.05
깊은 복사와 얕은 복사를 실험해 볼 예정이다.

1. 얕은복사에서의 동적할당 데이터와 깊은복사에서의 동적할당 데이터 실험.
얕은 복사로 동적할당 데이터가 있는 객체를 복사하면, 그 데이터는 복사된다.
따라서, 객체1을 객체2에 복사했을경우, 둘중 하나의 객체를 손댓을 경우 다른 객체에도 영향을 미치게된다.
허나, 깊은 복사의 경우 새로 메모리를 할당해 값만 복사하기 때문에, 이런 문제가 일어나지 않는다.
*/

class CShallowCopy
{
public:
	CShallowCopy()
	{
		m_ptnum = new int;
		*m_ptnum = 100;
	}
	CShallowCopy(const CShallowCopy* ori)
	{
		m_ptnum = ori->m_ptnum;
	}
public:
	int* m_ptnum;
	
};

class CDeepCopy
{
public:
	CDeepCopy() : m_ptnum(nullptr)
	{
		m_ptnum = new int;
		*m_ptnum = 100;
	}
	CDeepCopy(const CDeepCopy* ori)
	{
		m_ptnum = new int;
		*m_ptnum = *(ori->m_ptnum);
	}
public:
	int* m_ptnum;


};
int main()
{
	CShallowCopy* ShallowCopyObj1 = new CShallowCopy();
	CShallowCopy* ShallowCopyObj2 = new CShallowCopy(ShallowCopyObj1);

	std::cout << ShallowCopyObj1->m_ptnum << " " << *ShallowCopyObj1->m_ptnum << std::endl;
	std::cout << ShallowCopyObj2->m_ptnum << " " << *ShallowCopyObj2->m_ptnum << std::endl;

	CDeepCopy* DeepCopyObj1 = new CDeepCopy();
	CDeepCopy* DeepCopyObj2 = new CDeepCopy(DeepCopyObj1);

	std::cout << DeepCopyObj1->m_ptnum << " " << *DeepCopyObj1->m_ptnum << std::endl;
	std::cout << DeepCopyObj2->m_ptnum << " " << *DeepCopyObj2->m_ptnum << std::endl;
}