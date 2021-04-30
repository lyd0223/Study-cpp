#pragma once
#include "Item.h"
#include <string>
#include <vector>

class Item;
class Inventory
{
	int itemNum = 0;
	vector<Item> mItem;
	int myMoney = 100000;

public:
	void Print();
	void BuyItem(Item item);
};

