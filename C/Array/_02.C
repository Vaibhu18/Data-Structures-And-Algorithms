// C program to Insert an Element in the Sorted Array

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of Array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements : ", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Your entered array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int temp;
    printf("How much element to be insert : ");
    scanf("%d", &temp);
    n += temp;
    printf("Enter %d elements : ", temp);
    for (int i = n - temp; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("After adding new element array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}