#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter any number : ";
    cin >> num;
    int temp = num;
    int sum = 0;
    while (num > 0)
    {
        int rem = num % 10;
        sum += rem;
        num /= 10;
    }

    cout << "The sum of the digits of "<< temp << " is " << sum;
}