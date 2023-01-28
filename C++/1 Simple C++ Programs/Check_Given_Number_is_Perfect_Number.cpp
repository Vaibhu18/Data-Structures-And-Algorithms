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