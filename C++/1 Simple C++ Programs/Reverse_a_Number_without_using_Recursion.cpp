#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter any number : ";
    cin >> num;

    int ans = 0;
    while (num > 0)
    {
        int rem = num % 10;
        ans = ans * 10 + rem;
        num = num / 10;
    }
    cout << ans;
}