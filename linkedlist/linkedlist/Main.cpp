#include "List.h"
#include <iostream>

using namespace std;

int main()
{
	List<string> lists;
	
	lists.Push_Back("����");
	lists.Push_Back("����");
	lists.Push_Back("����");
	lists.Push_Back("��ö");
	lists.Push_Back("����");
	lists.Push_Back("����");
	
	List<string>::Iterator iter = lists.Begin();
	/*for (; iter != lists.End(); ++iter)
	{
		cout << *iter << endl;
		
	}*/
	lists.Erase(iter);
	iter = lists.Begin();
	lists.Erase(iter);
	lists.Erase("����");
	lists.Erase("��ö");
	lists.Print();
}