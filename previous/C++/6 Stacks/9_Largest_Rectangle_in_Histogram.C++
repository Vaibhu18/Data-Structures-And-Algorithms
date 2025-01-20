// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/899502805/

#include <iostream>
#include <climits>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int> stack;
    stack.push(-1);

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (stack.top() != -1 && arr[stack.top()] >= curr)
        {
            stack.pop();
        }
        ans[i] = stack.top();
        stack.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n)
{
    stack<int> stack;
    stack.push(-1);

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (stack.top() != -1 && arr[stack.top()] >= curr)
        {
            stack.pop();
        }
        ans[i] = stack.top();
        stack.push(i);
    }
    return ans;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    cout << area;
}