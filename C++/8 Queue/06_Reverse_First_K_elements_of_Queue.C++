// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void solve(queue<int> &q, int k, int n){
    // q = {1,2,3,4,5}

    stack<int> s;
    for(int i = 0; i < k; i++){
        int ele = q.front();
        q.pop();
        s.push(ele);
    }

    // S = {3,2,1}
    // Q = {4,5}

    while(!s.empty()){
        int ele = s.top();
        s.pop();
        q.push(ele);
    }

    // Q = {4,5,3,2,1}

    int t = n - k;
    while (t--)
    {
        int ele = q.front();
        q.pop();
        q.push(ele);
    }

    // Q = {3,2,1,4,5}
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