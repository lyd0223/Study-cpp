#include <iostream>
#include <time.h>
#include "Monster.h"
using namespace std;

class NoPoolMonster
{
	int hp;
	int mp;
	int arr[100000];
};
int main()
{
	clock_t start, end;
	
	start = clock();

	for (int i = 0; i < 1000000; i++)
	{
		NoPoolMonster* m1 = new NoPoolMonster();
		delete(m1);
	}

	end = clock();
	cout << "메모리풀 안쓴거 : "<< end - start << endl;

	Monster* m = new Monster();
	start = clock();

	for (int i = 0; i < 1000000; i++)
	{
		Monster* m2 = new Monster();
		delete(m2);
	}
	end = clock();
	cout << "메모리풀 쓴거 : " << end - start << endl;
}