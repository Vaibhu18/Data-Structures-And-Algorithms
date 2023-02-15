// https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0

#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int count, int size)
{
    if (count == size/2)
    {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    solve(s, count + 1, size);
    s.push(num);
}

int main()
{

    stack<int> s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i);
    }

    int count = 0;
    solve(s, count, s.size());
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}