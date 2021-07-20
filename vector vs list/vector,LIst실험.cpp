#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>
#include <time.h>
using namespace std;

//32bit운영체제에서는 사용가능한 메모리공간이 작아 64bit로 진행했다.
//벡터와 리스트의 중간 삭제를 실험해보았는데,
//실험 결과, 대부분의 경우 예상과 같이 벡터가 훨씬 빠르다.
//허나 반례가 있다. 객체의 크기가 상당히 큰 경우(나의경우 BigClass라는 4만비트의 크기인 클래스를 이용함)
//벡터의 경우 삭제햇을때, 객체를 복사하는데 상당한 시간이 걸리게되고, 결론적으로 리스트보다 느리게된다.
class BigClass
{
    int arr[10000];

};
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int start, end;
    start = clock();
    list<int> l1;
    vector<int> v1;
    for (int i = 0; i < 100000; i++)
    {
        l1.push_back(i);
        v1.push_back(i);
    }
    end = clock();
    cout << "int형 10만개 생성시간 :" << end - start << endl;
    list<BigClass> l;
    vector<BigClass> v;

    start = clock();
    for (int i = 0; i < 100000; i++)
    {
        BigClass b;
        l.push_back(b);
        v.push_back(b);
    }
    end = clock();

    cout << "BigClass형 10만개 생성시간 :" << end - start << endl;

    for (int i = 0; i < 10000; i++)
    {
        v.erase(v.begin() + 50000);
        cout << "벡터삭제";
    }


    for (int j = 0; j < 10000; j++)
    {
        list<BigClass>::iterator iter = l.begin();
        for (int i = 0; i < 50000; i++)
        {
            iter++;
        }
        l.erase(iter);
        cout << "리스트삭제" << endl;
    }
    cout << v.size() << endl;
    cout << l.size() << endl;
}