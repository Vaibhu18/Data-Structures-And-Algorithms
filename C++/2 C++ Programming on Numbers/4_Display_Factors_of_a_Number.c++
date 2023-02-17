#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter any number : ";
    cin >> num;
    
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cout<<i<<" " ;
        }
    }
}

/*
it uses a for loop to check all the numbers between 1 and the given number (n) and check if the number is divisible by any number between 1 and n. If it is divisible by any number then print that number is factors.
*/