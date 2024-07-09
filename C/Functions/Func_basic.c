#include <stdio.h>

void sum(int *num)
{
    *num = 25;
}
void main()
{
    int num1 = 15;
    int *num2 = &num1;
    sum(num2);
    printf("value : %d\n", *num2);
}