// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> solve(int arr[], int n, int k){
    deque<int> dq;
    vector<int>ans;

    for(int i = 0; i < k; i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }

    if(dq.size() > 0){
        ans.push_back(arr[dq.front()]);
    }else{
        ans.push_back(0);
    }

    for(int i = k; i < n; i++){

        // remove
        if(!dq.empty() && i - dq.front() >= k){
            dq.pop_front();
        }

        // addition
        if(arr[i] < 0){
            dq.push_back(i);
        }

        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }else{
            ans.push_back(0);
        }
    }
    return ans;
}

int main(){
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
   vector<int>ans = solve(arr, n, k);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}