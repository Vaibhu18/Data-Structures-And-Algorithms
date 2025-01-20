#include <iostream>
#include <stack>
using namespace std;

int solve(string str)
{
    if (str.length() % 2 == 1)
    {
        return -1;
    }
    stack<char> stack;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            stack.push(ch);
        }
        else
        {
            if (!stack.empty() && stack.top() == '{')
            {
                stack.pop();
            }
            else
            {
                stack.push(ch);
            }
        }
    }

    int a = 0, b = 0;
    while (!stack.empty())
    {
        if (stack.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        stack.pop();
    }
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main()
{
    string str = "{{{}";
    int ans = solve(str);
    cout <<ans;
}