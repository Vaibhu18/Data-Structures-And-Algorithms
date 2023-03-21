// https://leetcode.com/problems/permutations/submissions/917260313/

#include <iostream>
#include <vector>
using namespace std;

void solve(string str, vector<string> & ans, string output, int index){
    if(index >= str.length()){
        ans.push_back(str);
        return;
    }

    for(int i = index; i < str.length(); i++){
        swap(str[index], str[i]);
        output.push_back(str[i]);
        solve(str, ans, output, index+1);
        // backtraking
        swap(str[index], str[i]);
    }

}

int main(){
    string str = "abc";
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, ans, output, index);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }

}