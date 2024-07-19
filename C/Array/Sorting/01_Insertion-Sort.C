#include <stdio.h>

void InsertionSort(int arr[], int len);
void printArray(int arr[], int len);
int main()
{
    int arr[] = {5, 1, 3, 4, 2};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("\nBefore Sort : ");
    printArray(arr, len);

    InsertionSort(arr, len);

    printf("\nAfter Sort : ");
    printArray(arr, len);
}

void InsertionSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}