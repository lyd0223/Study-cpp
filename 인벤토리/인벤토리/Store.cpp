#include "Store.h"
#include "Item.h"

void Store::SetItem(Item item,int num)
{
	mItem.push_back(item);
	mItem[itemNum].num = num;
	
	itemNum++;
}
bool Store::SellItem(int n)
{
	if (mItem[n - 1].num < 1)
	{
		cout << "��� �����մϴ�." << endl;
		return 0;
	}
	else
	{
		mItem[n - 1].num--;
		cout << mItem[n - 1].name << "�� �����ϼ̽��ϴ�.\n";
		return 1;
	}
}
void Store::Print()
{
	cout <<"�ѹ�\t"<< "�̸�\t\t" << "����\t" << "����\t" << "��������\t" << "����\t" << endl;
	cout << "==============================================================================" << endl;
	for (int i = 0; i < itemNum; i++)
	{
		cout << i + 1 << "\t";
		cout << mItem[i].name << "\t";
		if (mItem[i].name.length() < 10)
			cout << "\t";
		cout << mItem[i].price << "\t";
		switch (mItem[i].itemType)
		{
		case 0:
			cout << "���\t";
			break;
		case 1:
			cout << "�Һ�\t";
			break;
		case 2:
			cout << "��Ÿ\t";
		}
		cout << mItem[i].num << "\t";
		cout << mItem[i].description << "\t";
		cout << endl;
	}
		cout << "==============================================================================" << endl;
}
Item Store::GetItem(int i)
{
	return mItem[i-1];
}
