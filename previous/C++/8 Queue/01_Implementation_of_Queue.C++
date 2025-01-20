#include <iostream>
#include <queue>
using namespace std;

void push(queue<int> &que)
{
    for (int i = 1; i <= 5; i++)
    {
        que.push(i);
    }

    while (!que.empty())
    {
        cout << que.front() << " ";
        que.pop();
    }

    for (int i = 1; i <= 5; i++)
    {
        que.push(i);
    }
}

void pop(queue<int> que)
{ 
    if (que.size() == 0)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        while (!que.empty())
        {
            int ans = que.front();
            cout << "Poped Element is : " << ans << endl;
            que.pop();
        }
    } 
}


void isEmpty(queue<int> que)
{
    if (que.size() == 0)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
}

int main()
{
    queue<int> que;
    push(que);
    cout << endl;
    pop(que);
    isEmpty(que);
}
