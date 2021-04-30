
#include <iostream>
using namespace std;

int main()
{
    //자료형 : 데이터 타입
    /*
    
       타입명      크기         표현범위
    
        int        4byte     -21억 ~ 21억 
     long long     8byte     -9,223,372,036,854,775,808~
       short       2byte     -32768 ~ 32767
      
       float       4byte      소수점 이하 7자리까지
       double      8byte      소수점이하 15자리까지
      
        bool       1byte       true(1) or false(0)
        
        char       1byte       문자한개
       string 문자의 수 + 1byte  

    unsigned : 음수없이 양수만 존재.
    unsigned int : 0~42억
    */
    
    /*
    변수 선언 규칙
    1. 언어에서 사용하는 키어드 변수이름으로 사용불가능 ex)int
    2. 알파벳,숫자,_로만 구성가능
    3. 대소문자 구분가능
    4. 이미 사용중인 변수이름 사용불가
    5. 이름사이에 띄어쓰기 사용불가
    */
    
    // 대입 연산자 ( = ) : 변수 대입.
    
    
    string name, birthday, address, favorite;
    int hp = 100,age;

    while (hp != 0) 
    {
        
        cout << "이름입력 : " ;
        cin >> name;
        cout << "생일입력 : " ;
        cin >> birthday;
        cout << "나이입력 : " ;
        cin >> age; 
        cout << "주소입력 :" ;
        cin >> address;
        cout << "가장좋아하는것 :" ;
        cin  >> favorite;

        cout << "\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
        cout << "이름 : " << name << endl;
        cout << "나이 : " << name << endl;
        cout << "생일 : " << birthday << endl;
        cout << "주소 : " << address << endl;
        cout << "가장 좋아하는것은 " << favorite << " 입니다";
        cout << "\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";

        cout << "끄려면 0 다시하려면 1 \n ";
        cin >> hp;
        cout << endl << endl << endl << endl;
    }

    
    
}

//나이 생년월일 등등 정보입력받고 입력받은 정보를 가지고 자기소개문을 출력
//
// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
