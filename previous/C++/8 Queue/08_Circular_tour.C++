// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1

#include <iostream>
using namespace std;

int solve(int petrol[], int distance[], int n)
{
    int defi = 0;
    int balance = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        balance += petrol[i] - distance[i];
        if (balance < 0)
        {
            defi += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (defi + balance >= 0)
    {
        return start;
    }
    else
    {
        cout << "tour is not completed" << endl;
    }
}

int main()
{
    int petrol[] = {4, 6, 7, 4};
    int distance[] = {6, 5, 3, 5};
    int n = sizeof(petrol) / sizeof(petrol[0]);
    cout << "Circular tour is completed from : " << solve(petrol, distance, n) << " Position"<<endl;;
}