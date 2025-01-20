// Sum of minimum and maximum elements of all subarrays of size k.
// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

#include <iostream>
#include <deque>
using namespace std;

void solve(int arr[], int k, int n){
    deque<int> maxi(k);
    deque<int> mini(k);

   for(int i = 0; i < k; i++){
    while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
        maxi.pop_back();
    }

    while(!mini.empty() && arr[mini.back()] >= arr[i]){
        mini.pop_back();
    }

    maxi.push_back(i);
    mini.push_back(i);
   }

   int ans = 0;
   ans += arr[maxi.front()] + arr[mini.front()];

   for(int i = k; i < n; i++){

    // remove first element from window
    while(!maxi.empty() && i - maxi.front() >= k){
        maxi.pop_front();
    }

    while(!mini.empty() && i - mini.front() >= k){
        mini.pop_front();
    }

    // Addition
    while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
        maxi.pop_back();
    }

    while(!mini.empty() && arr[mini.back()] >= arr[i]){
        mini.pop_back();
    }

    maxi.push_back(i);
    mini.push_back(i);
    ans += arr[maxi.front()] + arr[mini.front()];
   }

   cout<<ans;
}


int main(){
    int arr[7] = {2,5,-1,7,-3,-1,-2};
    int k = 4;
    int n = 7;

    solve(arr, k, n);
}