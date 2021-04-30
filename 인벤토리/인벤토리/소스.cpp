#include "Inventory.h"
#include "Store.h"
#include "Item.h"

using namespace std;


/*
1.����ȭ�����ְ� �������� ������ �κ��丮
2. ���� �����ϸ� �������� �̵� �κ��丮�����ϸ� �κ��丮�̵�
3. ���� 5���� ������, �����ٸ�
4.����
5.�Ǹ�
6.�κ��丮���� > �����մ¼����� ������ ������

����,�κ��丮,������(����ü)
*/
int main()
{
	Inventory myInventory;
	Store store;
	vector<Item> vitem;
	Item item;

	item.SetItem("Į", "�� ��� Į�̴�.", EQUIP, 500, 0);
	vitem.push_back(item);
	item.SetItem("����", "���ø� ü���� ȸ���ȴ�.", USE, 100, 0);
	vitem.push_back(item);
	item.SetItem("�������� ����", "���� ���� ��ǰ�ϱ�?", ETC, 9999, 0);
	vitem.push_back(item);
	store.SetItem(vitem[0], 5);
	store.SetItem(vitem[1], 999);
	store.SetItem(vitem[2], 1);

	int a,b;
	

	while (1)
	{
		cout << "1.�κ��丮   2.����" << endl;
		cin >> a;
		cout << endl;
		cout << endl;
		switch (a)
		{
			case 2:
				store.Print();
				while (1)
				{
					cout << " ������ ��ȣ�� �Է��ϼ���(������ �������� 0�� �Է�) : ";
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
					cout << "�κ��丮�� ������ 0 ���Է��ϼ���";
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