#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <list>
#include <queue>
using namespace std;

int main()
{
    //priority_queue<int> pq;

    //pq.push(1);
    //pq.push(10);
    //pq.push(5);
    //
    //cout << pq.top() << " ";
    //pq.pop();
    //cout << pq.top() << " ";
    //pq.pop();
    //cout << pq.top() << " ";
    //pq.pop();

    list<int> li;
   
    li.push_back(1);
    li.push_back(10);
    li.push_back(5);

    list<int>::iterator iter;

    vector<int> v;

    for (int i = 1; i <=10; i++)
    {
        v.push_back(i);
    }
    
    //make_heap(v.begin(), v.end());
    v.push_back(100);
    //push_heap(v.begin(), v.end());
    make_heap(v.begin(), v.end());
    /*for (iter = li.begin(); iter != li.end(); iter++)
        cout << *iter << " ";*/
    for (auto a : v)
    {
        cout << a << endl;
    }
}