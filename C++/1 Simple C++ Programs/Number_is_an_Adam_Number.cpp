#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int num;
    cout << "Enter any number : ";
    cin >> num;

    int temp = num;

    // get squre of num ex num = 12 squre = 12 * 12 = 144
    int squre = num * num;
    int reverse1 = 0;
    int reverse2 = 0;
    int squreroot;

    // reverse the squre (144) to (441)
    while (squre > 0)
    {
        int rem = squre % 10;
        reverse1 = reverse1 * 10 + rem;
        squre = squre / 10;
    }

    // get root of squre (441), root of 441 is 21
    squreroot = sqrt(reverse1);

    // reverse the root 21 to 12
    while (squreroot > 0)
    {
        int rem = squreroot % 10;
        reverse2 = reverse2 * 10 + rem;
        squreroot /= 10;
    }

    // check num or reversed root is equal or not
    if (reverse2 == temp)
    {
        cout << temp << " is a Adam Number.";
    }
    else
    {
        cout << temp << " is not a Adam Number.";
    }
}

/*
num = 12
1) get squre of num  12 * 12 = 144
2) reverse the squre 144 => 441
3) get root from reversed squre 441 => 21
4) reverse the root 21 => 12
5) check reversed root or original num is equal or not.  12 == 12
*/