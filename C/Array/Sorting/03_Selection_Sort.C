#include <stdio.h>

void selectionSort(int arr[], int len);
void printArray(int arr[], int len);
int main()
{

    int arr[] = {5, 1, 3, 4, 2};
    int len = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, len);
    // printArray(arr, len);
    return 0;
}

void selectionSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int temp = arr[i];
        int minIndex = 0;
        for (int j = i+1; j < len; j++)
        {
            if (arr[j] < arr[i])
            {
                printf("%d\n", arr[j]);
            }
        }
        
        // arr[i] = arr[minIndex];
        // arr[minIndex] = temp;
    }
}

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
}