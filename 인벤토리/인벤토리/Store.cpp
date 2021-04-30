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
		cout << "재고가 부족합니다." << endl;
		return 0;
	}
	else
	{
		mItem[n - 1].num--;
		cout << mItem[n - 1].name << "을 구입하셨습니다.\n";
		return 1;
	}
}
void Store::Print()
{
	cout <<"넘버\t"<< "이름\t\t" << "가격\t" << "종류\t" << "남은개수\t" << "설명\t" << endl;
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
		cout << "==============================================================================" << endl;
}
Item Store::GetItem(int i)
{
	return mItem[i-1];
}
