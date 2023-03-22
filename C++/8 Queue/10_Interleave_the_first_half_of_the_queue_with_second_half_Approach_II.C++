// Interleave the first half of the queue with second half
// https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void solve(queue<int> &q, int n){
    stack<int>s;
    for(int i = 0; i < n; i++){
        int ele = q.front();
        s.push(ele);
        q.pop();
    }

    while(!s.empty()){
        int ele = s.top();
        q.push(ele);
        s.pop();
    }

    for(int i = 0; i < n; i++){
        int ele = q.front();
        q.push(ele);
        q.pop();
    }

    for(int i = 0; i < n; i++){
        int ele = q.front();
        s.push(ele);
        q.pop();
    }

     while(!s.empty()){
        int ele = s.top();
        q.push(ele);
        s.pop();
        ele = q.front();
        q.push(ele);
        q.pop();
    }

}

int main()
{
    queue<int> q;
    for (int i = 1; i <= 6; i++)
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