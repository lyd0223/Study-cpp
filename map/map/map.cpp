#include <iostream>
#include<vector>
#include <map>

using namespace std;

int main()
{
	map<int, string> student;
	
	student.insert(make_pair(27,"����"));
	student.insert(make_pair(28,"����"));
	student.insert(make_pair(29,"�ѱ�"));
	student.insert(make_pair(11,"����"));
	student.insert(make_pair(13,"�N��"));
	student[100] = "������";
	student.find(12);
	vector<int> v;
	map<int, string>::iterator iter;
	for (iter = student.begin(); iter != student.end(); iter++)
	{ 
		cout << iter->first << " " << iter->second << endl;
	}
	cout << endl << endl;
	
	for (int i = 0; i < 1000; i++)
	{																					
		cout << student[i] << endl;
	}
	cout << endl << endl;

	cout << student[11];

	
}