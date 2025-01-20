// https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?leftPanelTab=0

#include <iostream>
#include <stack>
using namespace std;

void inserAtBottom(stack<int>& s, int num){
    if(s.empty()){
        s.push(num);
        return;
    }
    int ele = s.top();
    s.pop();
    inserAtBottom(s, num);
    s.push(ele);
}

void solve(stack<int>&s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    solve(s);
    inserAtBottom(s, num);
}

int main(){
    stack<int>s;
    for(int i = 1; i <= 5; i++){
        s.push(i);
    }

    solve(s);

while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}