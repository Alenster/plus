﻿#pragma once
#include <iostream>



#define NUMBER_SYSTEM_BASE_CODE -1;
#define NUMBER_SYSTEM_BASE_TEXT "Система счислений меньше 2!"; //#define NUMBER_SYSTEM_BASE_TEXT "The base of the number system is less than 2!";

#define NUMBER_NOT_NULL_CODE 101;
#define NUMBER_NOT_NULL_TEXT "Число не может быть 0!";  //#define NUMBER_NOT_NULL_TEXT "The number must not be zero!";

using namespace std;

int main()
{
    cout << "Hello World!\n";
    setlocale(LC_ALL, "Russian");
}

char digit(int num)
{
    switch (num) {
    case 0: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
    case 10: return 'A';
    case 11: return 'B';
    case 12: return 'C';
    case 13: return 'D';
    case 14: return 'E';
    case 15: return 'F';
    }
}

class NumberError
    {

    };
class NumberSystemBase :NumberError {
public:
    virtual const char* getMessage() { return NUMBER_SYSTEM_BASE_TEXT; };
    virtual int getCode() { return NUMBER_SYSTEM_BASE_CODE; };

};

int integerPart(int a, int p, char* s) {

    if (p < 2) {
        throw new NumberSystemBase();
    }

    int num = (int)a;
    int rest = num % p;
    num /= p;
    if (num == 0)
    {
        s[0] = digit(rest); return 1;
    }
    int k = integerPart(num, p, s);
    s[k++] = digit(rest);
    return k;
}