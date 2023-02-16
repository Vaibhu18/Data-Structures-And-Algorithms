// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTab=0

#include <iostream>
#include <stack>
using namespace std;

    // Update Stack 
void solve(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    solve(s, x);
    s.push(num);
}

int main()
{
    // Stack Creation 
    stack<int> s;
    for (int i = 4; i <= 10; i += 2)
    {
        s.push(i);
    }

    int ele = 2;
    solve(s, ele);

    // Print Stack
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}