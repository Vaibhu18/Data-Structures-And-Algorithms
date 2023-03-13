// https://www.codingninjas.com/codestudio/problems/reverse-the-string_799927?leftPanelTab=1

#include <iostream>
using namespace std;

void reverse(string &str, int start, int end)
{
    if (start > end)
    {
        return;
    }
    swap(str[start], str[end]);
    start++;
    end--;
    reverse(str, start, end);
}

int main()
{
    string str = "Hello World";
    reverse(str, 0, str.length() - 1);
    cout << str << endl;
}