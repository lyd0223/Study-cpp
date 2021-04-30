#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <Windows.h>
using namespace std;

#define SizeX 10
#define SizeY 10

string _map[SizeY][SizeX] =
{
	{"□","□","□","□","□","□","□","□","□","□"},
	{"□","□","□","□","□","□","□","□","□","□"},
	{"□","□","□","□","□","□","□","□","□","□"},
	{"□","□","□","□","□","□","■","□","□","□"},
	{"□","□","□","□","□","□","■","□","□","□"},
	{"□","□","□","■","□","□","□","□","□","□"},
	{"□","□","□","■","■","□","□","□","□","□"},
	{"□","□","□","□","□","□","□","□","□","□"},
	{"□","□","□","□","□","□","□","□","□","□"},
	{"□","□","□","□","□","□","□","□","□","□"},
};

/*
1.재귀함수로 구현
2.stack으로 구현
3.queue로 구현.

*/


void Print()
{
	system("cls");
	for (int y = 0; y < SizeY; y++)
	{
		for (int x = 0; x < SizeX; x++)
		{
			cout << _map[y][x] << " ";
		}
		cout << endl;
	}
}
//재귀함수로 구현
void FloodFill(int x,int y) 
{
	if (_map[y][x] == "□")
	{
		_map[y][x] = "■";
		system("cls");
		Print();
		FloodFill(x, y - 1);
		FloodFill(x, y + 1);
		FloodFill(x-1 , y);
		FloodFill(x+1, y);
	}
	
}
//스택으로 구현
stack<pair<int,int>> s;
bool check[SizeY][SizeX];
void FloodFillStack(int x, int y)
{
	if (_map[y][x] == "□")
	{
		_map[y][x] = "■";
		s.push({ x + 1,y });
		s.push({ x - 1,y });
		s.push({ x,y - 1 });
		s.push({ x,y + 1 });
	}
	while (!s.empty())
	{
		
		if (_map[s.top().second][s.top().first] == "□")
		{
			_map[s.top().second][s.top().first] = "■";
			
			s.push({ s.top().first + 1, s.top().second });
			s.push({ s.top().first - 1, s.top().second });
			s.push({ s.top().first, s.top().second + 1 });
			s.push({ s.top().first, s.top().second - 1 });
			Sleep(1000);
			
			Print();
		}
		else
			s.pop();
	}
	
}

void FloodFillQueue(int indexX, int indexY)
{
	queue<pair<int,int>> flood;
	flood.push({ indexX, indexY });

	while (flood.empty() == false)
	{
		int x = flood.front().first;
		int y = flood.front().second;
		flood.pop();

		if (_map[y][x] == "■")
			continue;
			
		_map[y][x] = "■";

		flood.push({ x - 1,y });
		flood.push({ x + 1,y });
		flood.push({ x   ,y - 1 });
		flood.push({ x   ,y + 1 });
		Print();

	}

}
struct FloodInfo
{
	int x;
	int y;
	int level;
};
void FloodFill(int indexX, int indexY, int level)
{
	queue<pair<int, int>> flood;
	flood.push({ indexX, indexY });
	while (!flood.empty())
	{
		int x = flood.front().first;
		int y = flood.front().second;
		level = abs(indexX - x) + abs(indexY - y);
		flood.pop();

		if (_map[y][x] == "■"|| _map[y][x] == "★"|| _map[y][x] == "◆"|| _map[y][x] == "♥" || _map[y][x] == "♠")
			continue;
		if(level == 1)
			_map[y][x] = "★";
		else if(level ==2)
			_map[y][x] = "◆";
		else if (level == 3)
			_map[y][x] = "♥";
		

		flood.push({ x - 1,y });
		flood.push({ x + 1,y });
		flood.push({ x   ,y - 1 });
		flood.push({ x   ,y + 1 });
		Print();
		if (level > 5)
			break;

	}
}
int main()
{
	FloodFill(SizeX / 2, SizeY / 2,1);

	return 0;
}
