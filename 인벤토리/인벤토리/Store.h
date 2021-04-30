#pragma once
#include "Item.h"
#include <string>
#include <vector>

class Item;
class Store
{
	int itemNum = 0;
	vector<Item> mItem;

public:
	void SetItem(Item item, int num);
	void Print();
	bool SellItem(int n);
	Item GetItem(int i);

};

