// https://leetcode.com/problems/subsets/submissions/916630690/

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> arr, vector<vector<int>> &ans, vector<int> output, int index)
{
    if (index >= arr.size())
    {
        ans.push_back(output);
        return;
    }

    solve(arr, ans, output, index + 1);

    int element = arr[index];
    output.push_back(element);
    solve(arr, ans, output, index + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(arr, ans, output, index);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << i + 1 << " : ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}