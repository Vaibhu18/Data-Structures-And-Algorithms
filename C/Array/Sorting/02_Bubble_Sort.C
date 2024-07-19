#include <stdio.h>

void BubbleSort(int arr[], int len);
void PrintArray(int arr[], int len);

int main()
{
    int arr[] = {5, 1, 3, 4, 2};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("\nBefore Sort : ");
    PrintArray(arr, len);

    BubbleSort(arr, len);

    printf("\nAfter Sort : ");
    PrintArray(arr, len);

    return 0;
}

void BubbleSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void PrintArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
}