// vietnam gamble.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ctime>
#include <string>
#include<conio.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int card[52] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13 };


    int count3 = 0;

    for (int i = 0; i < 100; i++)
    {

        int randomnum1 = rand() % 52;
        int randomnum2 = rand() % 52;
        if (card[randomnum1] == 0)continue;
        if (card[randomnum2] == 0)continue;
        int temp = card[randomnum1];
        card[randomnum1] = card[randomnum2];
        card[randomnum2] = temp;
    }



    // 카드셔플 끝

    int mycard1 = rand() % 52;
    int mycard2 = rand() % 52;
    int my_money = 1000;
    int com_money = 1000;
    int p1;
    int com;

    while (true)
    {
        while (true)
        {
            cout << "카드 2장 뽑았습니다.." << endl;
            
            if (card[mycard1] == 0)
            {
                continue;
            }

            if (card[mycard1] == 11)
            {
                cout << "당신의 첫번째 카드는 : J 입니다." << endl;
                break;
            }
            else if (card[mycard1] == 12)
            {
                cout << "당신의 첫번째 카드는 : Q 입니다." << endl;
                break;
            }
            else if (card[mycard1] == 13)
            {
                cout << "당신의 첫번째 카드는 : K 입니다." << endl;
                break;
            }
            cout << "당신의 첫번째 카드는 : " << card[mycard1] << " 입니다." << endl;
            break;
        }
        while (true)
        {

            if (mycard2 == 0)
            {
                continue;
            }
            if (mycard1 == mycard2)
            {
                continue;
            }

            else if (card[mycard2] == 11)
            {
                cout << "당신의 첫번째 카드는 : J 입니다." << endl;
                break;
            }
            else if (card[mycard2] == 12)
            {
                cout << "당신의 첫번째 카드는 : Q 입니다." << endl;
                break;
            }
            else if (card[mycard2] == 13)
            {
                cout << "당신의 첫번째 카드는 : K 입니다." << endl;
                break;
            }
            cout << "당신의 두번째 카드는 : " << card[mycard2] << " 입니다." << endl;
            break;

        }



        cout << "컴퓨터가 한장 뽑았습니다." << endl;
        cout << "아무키나 눌러주세요. " << endl;
        int any1 = _getch();

        system("cls");
        int com_ran = rand() % 13 + 1;
        while (true)
        {
            if (com_ran != mycard1 && com_ran != mycard2)
            {
                card[com_ran];
                break;
            }


        }

        //카드 2장 뽑고 카드한장 뒤집어 놓음
        cout << "아아" << endl;
        while (true)
        {
            cout << "소지금 : " << my_money << endl;
            cout << "배팅하세요." << endl;
            cin >> p1;
            if (p1 > my_money)
            {
                cout << "대출까지 끌어서 돈을 쓰기에는 너무 아깝습니다." << endl;
                cout << "다시 시도하세요." << endl;
                continue;
            }
            if (p1 == 0)
            {
                cout << "공짜로 도박을 할 수 없습니다." << endl;
                cout << "다시 시도하세요." << endl;
            }
            cout << " 당신이 배팅한 금액은 : " << p1 << " 입니다." << endl;
            break;
        }

        cout << "뽑은 카드를 공개합니다!" << endl;
        while (true)
        {
            if (card[com_ran] == 11)
            {
                cout << "카드는 바로 !! J 였습니다." << endl;
                break;
            }
            else if (card[com_ran] == 12)
            {
                cout << "카드는 바로 !! Q 였습니다." << endl;
                break;
            }
            else if (card[com_ran] == 13)
            {
                cout << "카드는 바로 !! K 였습니다." << endl;
                break;
            }
            cout << "카드는 바로 !! " << card[com_ran] << " 입니다." << endl;
            break;
        }
        // 배팅

        while (true)
        {
            if (card[mycard1] < card[com_ran] && card[com_ran] < card[mycard2])
            {
                cout << "당신이 승리하였습니다." << endl;
                my_money = my_money + p1;
                cout << "현재 소지금 : " << my_money << endl;
                break;
            }
            else if (card[mycard2] < card[com_ran] && card[com_ran] < card[mycard1])
            {
                cout << "당신이 승리하였습니다." << endl;
                my_money = my_money + p1;
                cout << "현재 소지금 : " << my_money << endl;
                break;
            }
            else if (card[mycard1] <= card[mycard2] && card[mycard2] < card[com_ran])
            {
                cout << "당신이 패배하였습니다." << endl;
                my_money = my_money - p1;
                cout << "현재 소지금 : " << my_money << endl;
                break;
            }
            else if (card[mycard2] < card[mycard1] && card[mycard2] <= card[com_ran])
            {
                cout << "당신이 패배하였습니다." << endl;
                my_money = my_money - p1;
                cout << "현재 소지금 : " << my_money << endl;
                break;
            }
            else if (card[com_ran] <= card[mycard1] && card[mycard1] < card[mycard2])
            {
                cout << "당신이 패배하였습니다." << endl;
                my_money = my_money - p1;
                cout << "현재 소지금 : " << my_money << endl;
                break;
            }
            else if (card[com_ran] <= card[mycard2] && card[mycard2] < card[mycard1])
            {
                cout << "당신이 패배하였습니다." << endl;
                my_money = my_money - p1;
                cout << "현재 소지금 : " << my_money << endl;
                break;
            }
        }

        for (int i = 0; i < 52; i++)
        {
            if (card[mycard1] == card[i])
            {
                card[i] = 0;
            }
        }
        for (int i = 0; i < 52; i++)
        {
            if (card[mycard2] == card[i])
            {
                card[i] = 0;
            }
        }

        for (int i = 0; i < 52; i++)
        {
            if (card[i] == 0)
            {
                count3++;
            }
        }
        //승패
        if (count3 >= 53)
        {
            cout << "카드가 다 떨어졌습니다." << endl;
            break;

        }

        if (my_money <= 0)
        {
            cout << " 돈이 다 떨어졌습니다." << endl;
            break;
        }
    }




}
