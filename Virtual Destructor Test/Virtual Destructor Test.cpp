#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class CParent
{
public:
    CParent()
    {
        std::cout << "CParent" << std::endl;
    }
    virtual ~CParent()
    {
        std::cout << "~CParent" << std::endl;
    }
};

class CChild :public CParent
{
public:
    CChild()
    {
        std::cout << "CChild" << std::endl;
    }
    ~CChild()
    {
        std::cout << "~CChild" << std::endl;
    }
};
int main()
{
    //부모생성자 > 자식생성자 > 자식소멸자 > 부모소멸자
    //CChild child;

    //부모소멸자에 virtual 안붙일시 : 부모생성자 > 자식생성자 > 부모소멸자
    //부모소멸자에 virtual 붙일시   : 부모생성자 > 자식생성자 > 자식소멸자 > 부모소멸자
    //부모소멸자에 virtual을 붙이지 않는다면, 객체가 무엇인지 판단하지않고, 부모 소멸자만 호출하고 끝이난다.
    CParent* child = new CChild;
    delete child;
}