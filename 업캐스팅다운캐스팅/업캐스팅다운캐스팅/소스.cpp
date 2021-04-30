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
		cout << " 나는 몬스터다. " << endl;
	};
};

class Ork : public Monster
{
public:
	void print()override
	{
		cout << " 나는 오크다. " << endl;
	}
};
class Troll : public Monster
{
public:
	void print()override
	{
		cout << " 나는 트롤이다. " << endl;
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