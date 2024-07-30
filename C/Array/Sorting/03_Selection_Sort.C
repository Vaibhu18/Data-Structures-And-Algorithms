#include <stdio.h>

void selectionSort(int arr[], int len);
void printArray(int arr[], int len);
int main()
{

    int arr[] = {5, 1, 3, 4, 2};
    int len = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, len);
    printArray(arr, len);
    return 0;
}

void selectionSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int minIndex = i;
        for (int j = i; j < len; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
}