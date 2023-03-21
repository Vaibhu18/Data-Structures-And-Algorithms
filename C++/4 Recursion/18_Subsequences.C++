// https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=1

#include <iostream>
#include <vector>
using namespace std;

void solve(string str, vector<string> &ans, string output, int index)
{
    if (index >= str.length())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }

    solve(str, ans, output, index + 1);

    char element = str[index];
    output.push_back(element);

    solve(str, ans, output, index + 1);
}

int main()
{
    string str = "abc";
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, ans, output, index);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}