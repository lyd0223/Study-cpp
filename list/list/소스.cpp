#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List *lists = new List();
	lists->Push_Back(5);
	lists->Push_Back(111);
	lists->Push_Back(5000);
	lists->Push_Back(100);
	lists->Print();
	
	delete(lists);
}