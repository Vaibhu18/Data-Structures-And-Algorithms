#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long num;
    cout << "Enter any number : ";
    cin >> num;
    long temp = num;
    long sum = 0;
    int size = trunc(log10(temp)) + 1;

    while (num > 0)
    {
        int rem = num % 10;
        int abc = 1;
        for (int i = 0; i < size; i++)
        {
            abc *= rem;
        }
        sum += abc;
        num = num / 10;
    }
    if (temp == sum)
    {
        cout << "Number is Armstrong";
    }
    else
    {
        cout << "Number is Not armstrong";
    }
}