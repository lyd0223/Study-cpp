#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
	
	BST bst;
	bst.Insert(28, "�Ӽ���");
	bst.Insert(60, "������");
	bst.Insert(30, "�ӿ���");
	bst.Insert(10, "�ֱ�����");

	string result;
	if (bst.TryGetValue(30, &result))
	{
		cout << result << endl;
	}
}