#include "Inventory.h"
#include "Item.h"


void Inventory::BuyItem(Item item)
{
	bool check = 0;
	if (myMoney <= item.price)
	{
		cout << "돈이부죠캐잉..." << endl;
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
	cout << "내 인벤토리" << endl;

	if (itemNum == 0)
	{
		cout << "\n텅벤토리 ㅠ_ㅠ" << endl;
	}
	else
	{

		cout << "이름\t\t" << "종류\t" << "남은개수\t" << "설명\t" << endl;
		for (int i = 0; i < itemNum; i++)
		{
			cout << mItem[i].name << "\t";
			if (mItem[i].name.length() < 10)
				cout << "\t";
			switch (mItem[i].itemType)
			{
			case 0:
				cout << "장비\t";
				break;
			case 1:
				cout << "소비\t";
				break;
			case 2:
				cout << "기타\t";
			}
			cout << mItem[i].num << "\t";
			cout << mItem[i].description << "\t";
			cout << endl;
		}
		cout << myMoney << "GOLD 소지중입니다." << endl;
	}
}