#include <stdio.h>

void DeleteFirstElement(int arr[], int *ele);
void DeleteLastElement(int arr[], int *ele);
void DeleteElementByPosition(int arr[], int *ele, int position);
void PrintArrayBeforeDeletion(int arr[], int ele);
void PrintArrayAfterDeletion(int arr[], int ele);

int main()
{
    int arr[6] = {1, 2, 3, 4, 5};
    int ele = 5;
    int len = sizeof(arr) / sizeof(arr[0]);
    PrintArrayBeforeDeletion(arr, ele);

    // DeleteFirstElement(arr, &ele);
    // DeleteLastElement(arr, &ele);
    DeleteElementByPosition(arr, &ele, 1);
    PrintArrayAfterDeletion(arr, ele);
    return 0;
}

// Delete First Element from array
void DeleteFirstElement(int arr[], int *ele)
{
    for (int i = 0; i < *ele; i++)
    {
        arr[i] = arr[i + 1];
    }
    *ele = *ele - 1;
}

// Delete Last Element from array
void DeleteLastElement(int arr[], int *ele)
{
    arr[*ele - 1] = 0;
    *ele = *ele - 1;
}

// Delete element by position
void DeleteElementByPosition(int arr[], int *ele, int position)
{
    if (position < 1 || position > *ele)
    {
        printf("\nError : invalid position");
        return;
    }

    for (int i = position - 1; i < *ele; i++)
    {
        arr[i] = arr[i + 1];
    }
    *ele = *ele - 1;
}

void PrintArrayBeforeDeletion(int arr[], int ele)
{
    printf("\nArrayBeforeDeletion : ");
    for (int i = 0; i < ele; i++)
    {
        printf("%d  ", arr[i]);
    }
}
void PrintArrayAfterDeletion(int arr[], int ele)
{
    printf("\nArrayAfterDeletion : ");
    for (int i = 0; i < ele; i++)
    {
        printf("%d  ", arr[i]);
    }
}