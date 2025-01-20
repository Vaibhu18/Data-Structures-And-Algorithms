#include <iostream>
using namespace std;

int main()
{
    int year;
    cout << "Enter any year : ";
    cin >> year;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        cout << year << " Year is leap year.";
    }
    else
    {
        cout << year << " year is not leap year.";
    }
}

/*
If the year is divisible by 4 and not divisible by 100, then it is a leap year.
If the year is divisible by 100, then it is not a leap year.
If the year is divisible by 400, then it is a leap year.
*/