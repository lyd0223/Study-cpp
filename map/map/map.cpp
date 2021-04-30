#include <iostream>
#include<vector>
#include <map>

using namespace std;

int main()
{
	map<int, string> student;
	
	student.insert(make_pair(27,"성현"));
	student.insert(make_pair(28,"동훈"));
	student.insert(make_pair(29,"둘기"));
	student.insert(make_pair(11,"응애"));
	student.insert(make_pair(13,"촏딩"));
	student[100] = "늙은이";
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