#include <string>
#include <iostream>

using namespace std;

enum State
{
	Idle,
	move,
	attck
};
struct Monster
{
	string monster_name;
	State state = Idle;
	int hp;
	int atk;
	int money;
};

int main()
{
	Monster orc = { "ø¿≈©",Idle,100,1,10 };

	cout << orc.state;
	cout << orc.monster_name;
	cout << orc.money;
}