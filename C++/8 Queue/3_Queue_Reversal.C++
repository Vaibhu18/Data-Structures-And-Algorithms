// https://practice.geeksforgeeks.org/problems/queue-reversal/1

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void printQ( queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> q;
    for(int i = 1; i<= 5; i++){
        q.push(i);
    }

    cout<<"Original Queue : ";
    printQ(q);

    stack<int> s;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        s.push(ele);
    }

    while(!s.empty()){
        int ele = s.top();
        s.pop();
        q.push(ele);
    }
    cout<<"Reversed Queue : ";
    printQ(q);
}