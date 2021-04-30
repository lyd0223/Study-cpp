#pragma once
#include <string>
#include <iostream>

using namespace std;

enum ItemType
{
	USE = 1,
	EQUIP = 0,
	ETC = 2
};
class Item
{
public:
	string name;
	string description;
	ItemType itemType;
	int price;
	int num;
	void SetItem(string name2, string des2, ItemType itemType2, int price2, int num2);
};
