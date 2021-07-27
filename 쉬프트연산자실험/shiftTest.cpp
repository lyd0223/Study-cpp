#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <time.h>
#include <bitset>

int main()
{

    unsigned char    r = 211;
    unsigned char    g = 157;
    unsigned char    b = 99;
    unsigned char    a = 33;
    unsigned int    Color = 0;

    Color |= r;
    Color <<= 8;
    Color |= g;
    Color <<= 8;
    Color |= b;
    Color <<= 8;
    Color |= a;
    
    unsigned char    r1;
    unsigned char    g1;
    unsigned char    b1;
    unsigned char    a1;

    //비트연산
    int start = clock();
    for (int i = 0; i < 1000000000; i++)
    {
        r1 = (Color >> 24) & 0xff;
        g1 = (Color >> 16) & 0xff;
        b1 = (Color >> 8) & 0xff;
        a1 = (Color) & 0xff;
    }
    int end = clock();
    std::cout << "비트연산결과 : " << (end - start) << std::endl;

    //곱하기
    start = clock();
    for (int i = 0; i < 1000000000; i++)
    {
        r1 = (Color * 0x01000000) & 0xff;
        g1 = (Color * 0x00010000) & 0xff;
        b1 = (Color * 0x00000100) & 0xff;
        a1 = (Color) & 0xff;
    }
    end = clock();
    std::cout << "일반연산결과 : " << (end - start) << std::endl;
    
    
}