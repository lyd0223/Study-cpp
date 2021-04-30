#include "Inventory.h"
#include "Store.h"
#include "Item.h"

using namespace std;


/*
1.메인화면이있고 선택지는 상점과 인벤토리
2. 상점 선택하면 상점으로 이동 인벤토리선택하면 인벤토리이동
3. 상점 5종류 아이템, 수량다름
4.구매
5.판매
6.인벤토리선택 > 갖고잇는수량과 아이템 보여줌

상점,인벤토리,아이템(구조체)
*/
int main()
{
	Inventory myInventory;
	Store store;
	vector<Item> vitem;
	Item item;

	item.SetItem("칼", "잘 드는 칼이다.", EQUIP, 500, 0);
	vitem.push_back(item);
	item.SetItem("포션", "마시면 체력이 회복된다.", USE, 100, 0);
	vitem.push_back(item);
	item.SetItem("성현이의 발톱", "어디다 쓰는 물품일까?", ETC, 9999, 0);
	vitem.push_back(item);
	store.SetItem(vitem[0], 5);
	store.SetItem(vitem[1], 999);
	store.SetItem(vitem[2], 1);

	int a,b;
	

	while (1)
	{
		cout << "1.인벤토리   2.상점" << endl;
		cin >> a;
		cout << endl;
		cout << endl;
		switch (a)
		{
			case 2:
				store.Print();
				while (1)
				{
					cout << " 구매할 번호를 입력하세요(상점을 나가려면 0을 입력) : ";
					cin >> b;
					cout << endl;
					if (b == 0)
					{
						break;
					}
					else
					{
						if (store.SellItem(b))
						{
							myInventory.BuyItem(store.GetItem(b));
						}
					}
				}
				break;
			case 1:
				myInventory.Print();
				while (1)
				{
					cout << "인벤토리를 끄려면 0 을입력하세요";
					cin >> b;
					cout << endl;
					if (b == 0)
					{
						break;
					}
				}
				break;
		}
	
	}

}