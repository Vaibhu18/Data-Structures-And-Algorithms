// https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104

#include <iostream>
#include <stack>
using namespace std;

bool check(string paren)
{
    stack<char> s;
    for (int i = 0; i < paren.length(); i++)
    {
        char ch = paren[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if (ch == ')' && top == '(' || ch == '}' && top == '{' || ch == ']' && top == '[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    string paren = "[]{}()";
    int ans = check(paren);
    if (ans == 0)
    {
        cout << "Not Balanced" << endl;
    }
    else
    {
        cout << "Balanced" << endl;
    }
}