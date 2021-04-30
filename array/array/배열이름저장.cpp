#include <iostream>
#include <algorithm>

using namespace std;

int arrout[5];
//함수 밖에서 배열을 정의하면 0으로 자동 초기화,
//함수 안에서 배열을 정의하면 쓰레기값들어감.

int main()
{
	// 범위기반 for문을 사용할때, 참조자를 사용하자. 
	// 범위기반 for문은 i로 배열의 요소들을 복사할뿐이기 때문에, 레퍼런스를 이용ㅇ해서 바꿔야한다.
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