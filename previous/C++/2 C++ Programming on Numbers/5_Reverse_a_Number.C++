#include <iostream>
using namespace std;

int reverseNumber(int num)
{
    int res = 0;
    while (num > 0)
    {
        int rem = num % 10;
        res = res * 10 + rem;
        num /= 10;
    }
    return res;
}

int main()
{
    int num;
    cout << "Enter any Number to reverse : ";
    cin >> num;

    cout << reverseNumber(num);
}
