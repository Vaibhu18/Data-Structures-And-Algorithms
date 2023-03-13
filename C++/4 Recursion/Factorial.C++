#include <iostream>
using namespace std;

int facto(int n)
{
    if (n == 0)
        return 1;

    int smallProblem = facto(n - 1);
    int bigProblem = n * smallProblem;
    return bigProblem;
}

int main()
{

    int ans = facto(5);
    cout << ans << endl;
}