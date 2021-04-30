//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	char code, s_code;
//	srand(time(NULL));
//	
//	s_code = rand()%26 +97;
//	while (1) 
//	{
//		cout << "비밀코드를 맞춰보세요 : ";
//		cin >> code;
//
//		if (code < 97 || code>122)
//			cout << "a~z만입력하세요" << endl;
//		else
//		{
//			if (s_code > code)
//				cout << code << "뒤에있음" << endl;
//			else if (s_code < code)
//				cout << code << "앞에있음" << endl;
//			else
//			{
//				cout << "정답!!" << endl;
//				break;
//			}
//		}
//
//		
//			
//
//	}
//}