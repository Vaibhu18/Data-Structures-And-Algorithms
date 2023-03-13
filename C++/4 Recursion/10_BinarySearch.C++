// https://www.codingninjas.com/codestudio/problems/binary-search_972?leftPanelTab=1

#include <iostream>
using namespace std;

bool search(int arr[], int start, int end, int k)
{
    if (start > end)
    {
        return false;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == k)
    {
        return true;
    }
    else if (arr[mid] > k)
    {
        return search(arr, start, mid - 1, k);
    }
    else
    {
        return search(arr, mid + 1, end, k);
    }
}

int main()
{
    int arr[6] = {2, 4, 6, 8, 10, 12};
    int size = 6;
    int key = 10;
    bool ans = search(arr, 0, 5, key);
    if (ans)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Fount" << endl;
    }
}