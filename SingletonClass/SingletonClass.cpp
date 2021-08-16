#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class CSingleTon
{
private:
	CSingleTon()
	{
		m_num = 100;
	}
	~CSingleTon()
	{

	}
	
private:
	static CSingleTon* m_pInst;
	int m_num;
public:
	static CSingleTon* GetInstance()
	{
		if (m_pInst == nullptr)
			m_pInst = new CSingleTon;
		
		return m_pInst;
	}
	static void Destroy()
	{
		if(m_pInst != nullptr)
			delete m_pInst;
		m_pInst = nullptr;
	}
	int GetNum()
	{
		return m_num;
	}
};
CSingleTon* CSingleTon::m_pInst = nullptr;


int main()
{
	std::cout << CSingleTon::GetInstance()->GetNum() << std::endl;
}