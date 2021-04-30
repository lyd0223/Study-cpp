#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
	
	BST bst;
	bst.Insert(28, "임성현");
	bst.Insert(60, "차성희");
	bst.Insert(30, "임영선");
	bst.Insert(10, "애기응애");

	string result;
	if (bst.TryGetValue(30, &result))
	{
		cout << result << endl;
	}
}