#include <iostream>
#include <unordered_map>
using namespace std;

//해싱함수 : 어떤값을 인자로 넣으면 int형으로 변환해서 반환하는함수.
// 암호화 또는 해쉬테이블에서쓰인다.
// 해쉬테이블에 
int HashFunc(const string& key)
{
	int temp = 1;
	int result = 0;
	for (int i = 0; i < key.length(); i++)
	{
		result = ((key[i] * temp)) + result;
		temp *= 7; //소수를 곱해주는것. 7이나 17이 중복이 최대한안된다.
	}

	if (result < 0)
		result *= -1;

	return result;
}

int main()
{
	unordered_map<string, int> map;
	map.insert(make_pair("이지훈", 30));
	//해싱함수 결과 % capacity => 배열의 인덱스
	//이런 식으로 데이터가 들어갈 배열의 인덱스를 뽑아낸 후에 그 위치에
	//데이터를 삽입한다
	//근데 이런식으로 하다보면 언젠가는 새로운 데이터를 집어 넣을 때 
	//중복되는 인덱스가 나올텐데 '해싱충돌'이 일어났다고 부른다
	//그래서 이런 상황이 발생했을 때 회피하는 방법이 있는데 가장 
	//많이 사용하는 방법이 '해시체이닝' 이라는 방법이다
	//두번째로 많이 쓰는????? 방법
	//리니어 프로빙(선형 탐색)
	//해싱 충돌이 난 지점부터 index하나씩 증가하면서 빈칸을 찾아 데이터를 
	//삽입하는 방법

}