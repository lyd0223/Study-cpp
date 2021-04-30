#include <iostream>
#include <vector>
using namespace std;

class Monster
{
public :
	int hp;
	int mp;

	virtual void print()
	{
		cout << " ���� ���ʹ�. " << endl;
	};
};

class Ork : public Monster
{
public:
	void print()override
	{
		cout << " ���� ��ũ��. " << endl;
	}
};
class Troll : public Monster
{
public:
	void print()override
	{
		cout << " ���� Ʈ���̴�. " << endl;
	}
};

int main()
{
	vector<Monster*> monsterlist;
	Monster* ork = new Ork();
	monsterlist.push_back(ork);
	Troll* troll = new Troll();
	monsterlist.push_back(troll);
	
	for (int i = 0; i < 2; i++)
	{
		monsterlist[i]->print();

	}
}