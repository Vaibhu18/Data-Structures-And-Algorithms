#include <stdio.h>
int main()
{
    int arr[5] = {5, 4, 2, 3, 1};
    int len = 5;

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

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}