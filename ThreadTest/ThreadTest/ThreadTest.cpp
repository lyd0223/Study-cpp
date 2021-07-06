#include <iostream>
#include <thread>
#include <windows.h>
#include <functional>
#include <vector>
using namespace std;

#define MAX 2000000000;
void ResourceLoading()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "���ҽ� �ε���...\n";
		Sleep(1000);
	}
	cout << "���ҽ� �ε��Ϸ� -----------\n";
}
void MapLoading()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "�� �ε���...\n";
		Sleep(1000);
	}
	cout << "�� �ε��Ϸ� -----------\n";
}
void Update()
{
	while (1)
	{
		cout << "���� ���ư�����... \n";
		Sleep(500);
	}
}
void Loading(vector<function<void()>> loadingList)
{
	for (int i = 0; i < loadingList.size(); i++)
	{
		loadingList[i]();
	}
}
int main()
{
	vector<function<void()>> loadingList;
	loadingList.push_back(&MapLoading);
	loadingList.push_back(&ResourceLoading);
	thread thread1(Loading,loadingList);
	//thread thread2();

	while (1)
	{
		Update();
	}
}