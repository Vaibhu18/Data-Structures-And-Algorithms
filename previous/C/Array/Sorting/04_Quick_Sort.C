#include <stdio.h>
void qs(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int arr[], int i, int j);

int main()
{
    int arr[] = {5, 1, 3, 4, 2};
    int len = sizeof(arr) / sizeof(arr[0]);

    qs(arr, 0, len - 1);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void qs(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        qs(arr, low, pivot - 1);
        qs(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }

        while (arr[j] > pivot && j > low)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, low, j);
    return j;
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}