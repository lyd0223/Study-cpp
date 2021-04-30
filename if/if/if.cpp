#include <iostream>
using namespace std;

int main()
{
	//제어문 if, while, switch 등 코드에서 분기를 나누는 문법
	
	/*
	1.if문 조건이 true면 코드A를실행한다. false면 B를 실행한다.
	if(조건)
	{ 코드A }
	코드B
	*/
	
	int num;
	
	cout << "수를 입력하세요" << endl;
	cin >> num;
	
	if (num % 2 == 1)
	{
		cout << num << "은 홀수입니다." << endl;
	}
	else
		cout << num << "은 짝수입니다." << endl;
	
	
	int a_score, b_score, c_score;
	int average;

	cout << "점수세개입력" << endl;
	cin >> a_score >> b_score >> c_score;
	
	average = (a_score + b_score + c_score) /3 ;
	cout << "평균점수는 " << average << endl;
	if (average > 70)
		cout << "합격" << endl;
	else cout << "불합격" << endl;

	//if else에 같은조건을 두개달면 아래꺼 씹힘.
}

