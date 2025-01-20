#include <iostream>
using namespace std;
int len1 = 0;
int len2 = 0;

class Stack
{
public:
    int *arr1;
    int *arr2;
    int top1;
    int top2;
    int size1;
    int size2;

    Stack(int size1, int size2)
    {
        this->size1 = size1;
        this->size2 = size2;

        arr1 = new int[size1];
        arr2 = new int[size2];

        top1 = -1;
        top2 = -1;
    }

    void push1(int ele)
    {
        if (size1 - top1 > 1)
        {
            top1++;
            arr1[top1] = ele;
            len1++;
        }
        else
        {
            cout << "Stack is OverFlow" << endl;
        }
    }

    void push2(int ele)
    {
        if (size2 - top2 > 1)
        {
            top2++;
            arr2[top2] = ele;
            len2++;
        }
        else
        {
            cout << "Stack is OverFlow" << endl;
        }
    }
};

class TwoStack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    TwoStack(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }
    void push1(int ele)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = ele;
        }
    }

    void push2(int ele)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = ele;
        }
    }
};

int main()
{
    Stack st(5, 5);
    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push1(4);
    st.push1(5);

    st.push2(6);
    st.push2(7);
    st.push2(8);
    st.push2(9);
    st.push2(10);

    TwoStack ts(len1 + len2);
    for (int i = 0; i < len1; i++)
    {
        ts.push1(st.arr1[i]);
    }
    
    for (int i = 0; i < len2; i++)
    {
        ts.push2(st.arr2[i]);
    }

    for (int i = 0; i < len1 + len2; i++)
    {
        cout << ts.arr[i] << " ";
    }
}