#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter any number : ";
    cin >> num;
    bool flag = true;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << num << " is a prime number.";
    }
    else
    {
        cout << num << " is not a prime number";
    }
}

// 5 7 11 13 17 19 23 29 31 37 41