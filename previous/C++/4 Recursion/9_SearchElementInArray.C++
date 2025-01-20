#include <iostream>
using namespace std;

bool find(int arr[], int size)
{

    if (size == 0)
    {
        return false;
    }

    if (arr[0] == 3)
    {
        return true;
    }
    else
    {
        bool rem = find(arr + 1, size - 1);
        return rem;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    bool ans = find(arr, size);
    if (ans)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Fount" << endl;
    }
}