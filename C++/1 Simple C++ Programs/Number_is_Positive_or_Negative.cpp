#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter any number : ";
    cin >> num;

    if (num >= 0)
    {
        cout << num << " is a positive number.";
    }
    else
    {
        cout << num << " is a negative number.";
    }
}