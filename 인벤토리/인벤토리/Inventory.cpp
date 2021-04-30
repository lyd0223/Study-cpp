#include "Inventory.h"
#include "Item.h"


void Inventory::BuyItem(Item item)
{
	bool check = 0;
	if (myMoney <= item.price)
	{
		cout << "���̺���ĳ��..." << endl;
	}
	else
	{
		
		for (int i = 0; i < itemNum; i++)
		{
			if (item.name == mItem[i].name)
			{

				mItem[i].num++;
				check = 1;
			}
		}
		if (check == 0)
		{
			mItem.push_back(item);
			mItem[itemNum].num = 1;

			itemNum++;
		}
		myMoney -= item.price;
	}
	
}
void Inventory::Print()
{
	cout << "�� �κ��丮" << endl;

	if (itemNum == 0)
	{
		cout << "\n�ֺ��丮 ��_��" << endl;
	}
	else
	{

		cout << "�̸�\t\t" << "����\t" << "��������\t" << "����\t" << endl;
		for (int i = 0; i < itemNum; i++)
		{
			cout << mItem[i].name << "\t";
			if (mItem[i].name.length() < 10)
				cout << "\t";
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
		cout << myMoney << "GOLD �������Դϴ�." << endl;
	}
}