#include "List.h"
#include <iostream>

using namespace std;

int main()
{
	List<string> lists;
	
	lists.Push_Back("성현");
	lists.Push_Back("문구");
	lists.Push_Back("지훈");
	lists.Push_Back("종철");
	lists.Push_Back("종성");
	lists.Push_Back("수정");
	
	List<string>::Iterator iter = lists.Begin();
	/*for (; iter != lists.End(); ++iter)
	{
		cout << *iter << endl;
		
	}*/
	lists.Erase(iter);
	iter = lists.Begin();
	lists.Erase(iter);
	lists.Erase("수정");
	lists.Erase("종철");
	lists.Print();
}