// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void solve(queue<int> &q, int k, int n){
    stack<int> s;
    for(int i = 0; i < k; i++){
        int ele = q.front();
        q.pop();
        s.push(ele);
    }

    while(!s.empty()){
        int ele = s.top();
        s.pop();
        q.push(ele);
    }

    int t = n - k;
    while (t--)
    {
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
}

int main(){
    queue<int> q({1,2,3,4,5});
    int k = 3;
    int n = q.size();
    solve(q, k, n);
   while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
   }
}