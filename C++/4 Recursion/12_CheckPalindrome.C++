#include <iostream>
using namespace std;

bool checkPalindrome(string str, int start, int end){
    if(start > end){
        return true;
    }
    if(str[start] != str[end]){
        return false;
    }else{
        start++;
        end--;
        return checkPalindrome(str, start, end);
    }
}

int main(){
    string str = "radara";
    bool ans = checkPalindrome(str, 0, str.length()-1);
    if(ans){
        cout<<"String is Palindrome"<<endl;
    }else{
        cout<<"String is not palindrome"<<endl;
    }
}