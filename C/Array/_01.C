#include <stdio.h>

int main()
{
    int row;
    int col;

    printf("Enter the length of row : ");
    scanf("%d", &row);

    printf("Enter the length of col : ");
    scanf("%d", &col);

    int arr[row][col];

    printf("Enter array elements : ");
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
   for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}