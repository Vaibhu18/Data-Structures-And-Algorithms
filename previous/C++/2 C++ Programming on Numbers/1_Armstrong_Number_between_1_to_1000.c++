#include <iostream>
#include <cmath>
using namespace std;

int check_Armstrong_Number(int num){
    long temp = num;
    long sum = 0;
    int size = trunc(log10(temp)) + 1;

    while (num > 0)
    {
        int rem = num % 10;
        int abc = 1;
        for (int i = 0; i < size; i++)
        {
            abc *= rem;
        }
        sum += abc;
        num = num / 10;
    }
    return sum;
}

int main()
{
    for(int i = 1; i <= 1000; i++){
        
        int num = check_Armstrong_Number(i);
        if (i == num)
    {
        cout << i <<" ";
    }

    }
    
}