#include <stdio.h>
void insertAtFirst(int *arr, int *ele, int len);
void insertAtEnd(int *arr, int *ele, int len);
void insertAtPosition(int *arr, int *ele, int len, int position, int newEle);
void printArray(int arr[], int);

int main()
{

    int arr[6] = {2, 4, 6, 8, 10};
    int ele = 5;
    int len = sizeof(arr) / sizeof(arr[0]);

    // insertAtFirst(arr, &ele, len);
    // insertAtEnd(arr, &ele, len);
    insertAtPosition(arr, &ele, len, 6, 24);
    printArray(arr, ele);
    return 0;
}

// Enter new Element at beginning of array
void insertAtFirst(int *arr, int *ele, int len)
{
    if (*ele < len)

    {
        for (int i = *ele; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = 12;
        *ele = *ele + 1;
    }
    else
    {
        printf("Error : Array is Full");
    }
}

// Enter new Element at the end of the array
void insertAtEnd(int *arr, int *ele, int len)
{
    if (*ele < len)
    {
        arr[*ele] = 12;
        *ele = *ele + 1;
    }
    else
    {
        printf("Error : Array is Full");
    }
}

// Enter new Element at the given position
void insertAtPosition(int *arr, int *ele, int len, int position, int newEle)
{
    if (position > len)
    {
        printf("Error : invalid position");
        return;
    }
    if (*ele < len)
    {
        for (int i = *ele; i >= 0; i--)
        {
            if (position - 1 != i)
            {
                arr[i] = arr[i - 1];
            }
            else
            {
                arr[position - 1] = newEle;
                *ele = *ele + 1;
                return;
            }
        }
    }
    else
    {
        printf("Error : Array is Full unable to insert at position");
    }
}

// print array elements
void printArray(int arr[], int ele)
{
    printf("\nArray : ");
    for (int i = 0; i < ele; i++)
    {
        printf("%d  ", arr[i]);
    }
}