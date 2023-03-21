// https://practice.geeksforgeeks.org/problems/max-rectangle/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <iostream>
#include <climits>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(int* arr, int n)
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

vector<int> prevSmallerElement(int* arr, int n)
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

int largestRectangleArea(int *heights, int n)
{
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
    return area;
}

int main()
{
    int M[4][4] = { {0, 1, 1, 0},
                    {1, 1, 1, 1},
                    {1, 1, 1, 1},
                    {1, 1, 0, 0} };
    int n = 4;
    int m = 4;

    int area = largestRectangleArea(M[0], m);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(M[i][j] != 0){
                    M[i][j] = M[i][j] + M[i-1][j];
                }else{
                    M[i][j] = 0;
                }
            }
            
            int newArea = largestRectangleArea(M[i], m);
            area = max(area, newArea);
        }
        cout<< area;
}