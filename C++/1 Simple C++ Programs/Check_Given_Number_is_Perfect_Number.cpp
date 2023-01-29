// 1

#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter any number : ";
    cin >> num;

    int div = 0, sum = 0;
    for (int i = 1; i < num; i++)
    {
        div = num % i;
        if (div == 0)
        {
            sum += i;
        }
    }
    if (sum == num)
    {
        cout << num << " is a perfect number.";
    }
    else
    {
        cout << num << " is not perfect number.";
    }
}

/*
a positive integer that is equal to the sum of its proper diviser

    (i = 1 to i < num)

    num = 28
    28 % 1 = 0
    28 % 2 = 0
    28 % 4 = 0
    28 % 7 = 0
    28 % 14 = 0

    1 + 2 + 4 + 7 + 14 = sum = 28
    num == sum : this is perfect number

*/