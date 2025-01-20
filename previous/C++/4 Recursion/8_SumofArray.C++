#include <iostream>
using namespace std;

int sumOfArray(int arr[], int size)
{

    if (size == 0)
    {
        return 0;
    }

    return arr[0] + sumOfArray(arr + 1, size - 1);
    int remain = sumOfArray(arr+1, size-1);
    int sum = arr[0] + remain;
    return sum;
}

int main()
{
    int arr[5] = {3, 2, 5, 1, 6};
    int size = 5;
    cout << "Sum of Array is : " << sumOfArray(arr, size) << endl;
}