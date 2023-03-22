// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void solve(string A){
    unordered_map<char, int>count;
    queue<int>q;
    string ans = "";

    for(int i = 0; i < A.length(); i++){
        char ch = A[i];
        count[ch]++;
        q.push(ch);

        while(!q.empty()){
            if(count[q.front()] > 1){
                q.pop();
            }else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    cout<<ans;
}

int main(){
    string s = "aabc";
    solve(s);
}