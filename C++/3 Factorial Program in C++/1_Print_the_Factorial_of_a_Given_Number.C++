#include<iostream>
using namespace std;

int getFactorial(int num){
    if(num <= 1){
        return 1 ;
    }else{
        return num * getFactorial(num-1);
    } 
}

int main(){
    int num;
    cout<<"Enter any number : ";
    cin>>num;
    cout<<"Factorial of " << num << " is "<< getFactorial(num); 
}