#include <iostream>
using namespace std;

void print(int n)
{
    if (n == 0)
    {
        cout << endl;
        return;
    }

    // Print in reverse order
    cout << n << " ";
    print(n - 1);
    // Print in serial order
    cout << n << " ";
}

int main()
{
    int n = 10;
    print(n);
}