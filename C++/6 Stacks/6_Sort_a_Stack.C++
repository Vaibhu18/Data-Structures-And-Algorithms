// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?leftPanelTab=0

#include <iostream>
#include <stack>
using namespace std;

void InsertForSort(stack<int> &stack, int ele){
    if(stack.empty() || stack.top() < ele){
        stack.push(ele);
        return;
    }
    int num = stack.top();
    stack.pop();
    InsertForSort(stack, ele);
    stack.push(num);
}

void solve(stack<int>&stack){
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    solve(stack);
    InsertForSort(stack, num);
}

int main()
{
    stack<int> s;
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(4);
    s.push(1);

    solve(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}