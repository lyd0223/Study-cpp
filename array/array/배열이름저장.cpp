#include <iostream>
#include <algorithm>

using namespace std;

int arrout[5];
//�Լ� �ۿ��� �迭�� �����ϸ� 0���� �ڵ� �ʱ�ȭ,
//�Լ� �ȿ��� �迭�� �����ϸ� �����Ⱚ��.

int main()
{
	// ������� for���� ����Ҷ�, �����ڸ� �������. 
	// ������� for���� i�� �迭�� ��ҵ��� �����һ��̱� ������, ���۷����� �̿뤷�ؼ� �ٲ���Ѵ�.
	int arr2[5]{ 1,10,4,4,6 };
	/*for (int &i : arr2)
	{
		cin >> i;
	}
	for (int i : arr2)
	{
		cout << i  << endl;
	}*/
	sort(arr2, arr2 + 5);
	for (int& i : arr2)
	{
		cout << i << endl;
	}

}