// Interleave the first half of the queue with second half
// https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

#include <iostream>
#include <queue>
using namespace std;

void solve(queue<int> &q, int n)
{
    queue<int> newQ;
    for (int i = 0; i < n; i++)
    {
        int ele = q.front();
        newQ.push(ele);
        q.pop();
    }

    while (!newQ.empty())
    {
        int ele = newQ.front();
        q.push(ele);
        newQ.pop();
        ele = q.front();
        q.push(ele);
        q.pop();
    }
}

int main()
{
    queue<int> q;
    for (int i = 11; i <= 20; i++)
    {
        q.push(i);
    }

    int n = q.size() / 2;

    solve(q, n);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}